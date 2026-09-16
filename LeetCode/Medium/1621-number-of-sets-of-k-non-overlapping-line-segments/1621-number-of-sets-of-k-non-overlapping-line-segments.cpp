class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        int total = n + k - 1;
        int r = 2 * k;

        if (r > total) return 0;

        // Compute C(total, r) % MOD
        long long numerator = 1;
        long long denominator = 1;

        auto modInverse = [&](long long base, long long exp) -> long long {
            long long res = 1;
            base %= MOD;
            while (exp > 0) {
                if (exp & 1) res = (res * base) % MOD;
                base = (base * base) % MOD;
                exp >>= 1;
            }
            return res;
        };

        for (int i = 1; i <= r; ++i) {
            numerator = (numerator * (total - i + 1)) % MOD;
            denominator = (denominator * i) % MOD;
        }

        return (numerator * modInverse(denominator, MOD - 2)) % MOD;
    }
};