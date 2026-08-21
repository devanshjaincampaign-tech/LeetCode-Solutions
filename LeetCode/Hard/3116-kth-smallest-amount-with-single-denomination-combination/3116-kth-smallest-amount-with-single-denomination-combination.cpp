class Solution {
private:
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / gcd(a, b)) * b;
    }

    // Counts how many distinct amounts <= target can be formed
    long long countMultiples(long long target, const vector<int>& coins) {
        int n = coins.size();
        long long total = 0;

        // Iterate through all non-empty subsets (1 to 2^n - 1)
        for (int mask = 1; mask < (1 << n); ++mask) {
            long long currentLcm = 1;
            int bitCount = 0;
            bool overflow = false;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    bitCount++;
                    currentLcm = lcm(currentLcm, coins[i]);
                    if (currentLcm > target) {
                        overflow = true;
                        break;
                    }
                }
            }

            if (overflow) continue;

            if (bitCount % 2 == 1) {
                total += (target / currentLcm);
            } else {
                total -= (target / currentLcm);
            }
        }

        return total;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int minCoin = *min_element(coins.begin(), coins.end());
        long long low = 1;
        long long high = 1LL * minCoin * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (countMultiples(mid, coins) >= k) {
                ans = mid;
                high = mid - 1; // Try to find a smaller valid amount
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};