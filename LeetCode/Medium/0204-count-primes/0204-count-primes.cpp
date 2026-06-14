class Solution {
public:
    int countPrimes(int n) {
        // LeetCode specifies strict strictly less than n
        if (n <= 2) return 0;

        // Initialize a boolean vector with true
        std::vector<bool> isPrime(n, true);
        
        // 0 and 1 are not prime numbers
        isPrime[0] = isPrime[1] = false;

        // Loop up to sqrt(n)
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                // Mark all multiples of i starting from i*i as false
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Count how many numbers are still marked as true
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;
            }
        }

        return count;
    }
};