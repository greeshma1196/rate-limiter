#include <iostream>
#include <unistd.h>
using namespace std;

namespace RateLimiter
{
    class TokenBucketAlgorithm
    {
    private:
        const int tokenBucketLowerLimit = 0;
        const int tokenBucketUpperLimit = 4;
        int tokenBucket = 4;
        const int rate = 1;

    public:
        // TokenBucketAlgorithm() = default;
        // ~TokenBucketAlgorithm();

        void parseRequests(int &currentRequestID, int numberOfRequests);
        void addToken();
    };
}
