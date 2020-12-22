// C++ solution.

// Sieve Method: Eratosthenes O(NloglogN)
class Solution {
public:
    int countPrimes(int n) {
        std::vector<bool> isprime(n+1, true);
        isprime[0] = false;
        isprime[1] = false;

        for (int i = 2; i*i <= n; i++) {
            if (isprime[i]) {
                for (int j = i*i; j <= n; j += i) {
                    isprime[j] = false;
                }
            }
        }
        // Note that the queston need to count the number of primes that LESS THAN n.
        // So we just use [0,n) as the range to count prime numbers.
        return std::count(isprime.begin(), isprime.end()-1, true);
    }
};

// Sieve Method: Euler O(N)
class Solution {
public:
    int countPrimes(int n) {
        std::vector<bool> isprime(n+1, true);
        std::vector<int> primes;
        isprime[0] = false;
        isprime[1] = false;

        for (int i = 2; i < n; i++) {
            if (isprime[i]) {
                primes.push_back(i);
            }
            for (int j = 0; i*primes[j] < n; j++) {
                isprime[i*primes[j]] = false;
                if (!(i % primes[j])) { break; }
            }
        }
        return primes.size();
    }
};