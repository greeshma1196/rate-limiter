#include "leaking-bucket-algo.h"
#include <thread>

void RateLimiter::LeakingBucketAlgorithm::processNewRequest(int maxNumberOfRequests)
{
    mtx.lock();
    int requestID = 1;
    while (requestID <= maxNumberOfRequests)
    {
        if (bucket.size() < bucketSize)
        {
            bucket.push(requestID);
            cout << "UPDATE: Added request " << requestID << " to the bucket" << endl;
        }
        else
        {
            cout << "FAIL: Bucket is full, request " << requestID << " denied" << endl;
        }
        requestID++;
    }
    mtx.unlock();
}

void RateLimiter::LeakingBucketAlgorithm::processRequestFromBucket()
{
    mtx.lock();
    cout << "Size of the bucket: " << bucket.size() << endl;
    while (bucket.size() > 0)
    {
        sleep(rate);
        int currentRequest = 0;
        while (currentRequest < outflowRate && bucket.size() > 0)
        {
            bucket.pop();
            cout << "SUCCESS: Request parsed successfully" << endl;
            currentRequest++;
        }
    }
    mtx.unlock();
}

int main()
{
    RateLimiter::LeakingBucketAlgorithm obj;
    const int numberOfRequests = 10;
    thread t1(&RateLimiter::LeakingBucketAlgorithm::processNewRequest, &obj, numberOfRequests);
    thread t2(&RateLimiter::LeakingBucketAlgorithm::processRequestFromBucket, &obj);

    t1.join();
    t2.join();

    return 0;
}