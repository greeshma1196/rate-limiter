#include "token-bucket-algo.h"
#include <thread>

void RateLimiter::TokenBucketAlgorithm::parseRequests(int &currentRequestID, int numberOfRequests)
{
    while (currentRequestID <= numberOfRequests)
    {
        if (tokenBucket > tokenBucketLowerLimit)
        {
            tokenBucket--;
            currentRequestID++;
            cout << "SUCCESS: Token parsed successfully" << endl;
        }
        else
        {
            cout << "FAIL: Token failed" << endl;
            break;
        }
    }
}

void RateLimiter::TokenBucketAlgorithm::addToken()
{
    sleep(rate);
    if (tokenBucket < tokenBucketUpperLimit)
    {
        tokenBucket++;
        cout << "UPDATE: New token added to the bucket" << endl;
    }
}

int main()
{

    RateLimiter::TokenBucketAlgorithm obj;
    const int numberOfRequests = 10;
    int currentRequest = 1;

    while (currentRequest <= numberOfRequests)
    {

        std::thread t1(&RateLimiter::TokenBucketAlgorithm::parseRequests, &obj, std::ref(currentRequest), numberOfRequests);
        std::thread t2(&RateLimiter::TokenBucketAlgorithm::addToken, &obj);

        t1.join();
        t2.join();
    }
    cout << "Processed all the requests" << endl;
    return 0;
}