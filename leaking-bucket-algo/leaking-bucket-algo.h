#include <iostream>
#include <unistd.h>
#include <queue>
#include <mutex>
using namespace std;

namespace RateLimiter
{
    class LeakingBucketAlgorithm
    {
    private:
        queue<int> bucket;
        const int bucketSize = 5;
        const int outflowRate = 2;
        const int rate = 1;
        mutex mtx;

    public:
        void processNewRequest(int maxNumberOfRequests);
        void processRequestFromBucket();
    };
}