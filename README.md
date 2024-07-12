# Rate Limiter

A rate limiter is used to control the rate of traffic sent by a client or a service. In terms of HTTP, it essentially limits the number of client requests that are allowed to be sent of a period of time.

## Benefits of Using a Rate Limiter

1. A rate limiter prevents Denial of Service attacks by blocking the excess calls.
2. It helps in reducing the cost by limiting the servers and allocating more resources to high priority APIs. It is extremely important for companies that use paid third party APIs.
3. Prevents servers from being overloaded.

## Algorithms

### 1. Token Bucket Algorithm

A token bucket is a container that can hold a predefined set of tokens. Each time a request is sent, a token is processed. If the bucket is empty then no requests can be processed until the token is refreshed in the bucket. New tokens are added periodically. For the sake of simplicity, in the program every 1 second a new token is added to the token bucket.

The number of buckets depends on the rate limiting rule. It is usually necessary that each API endpoint require a single bucket.

#### Pros

1. Easy to implement
2. Memory efficient
3. A request can go through as long as there are some tokens left

#### Cons

1. There are 2 parameters in the algorithm that will need to be tuned; one is the size of the token bucket and the other is the rate at which the tokens will be refilled

## Reference

1. System Design Interview by Alex Xu
