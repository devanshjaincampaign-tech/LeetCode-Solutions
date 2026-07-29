class Solution {
    long long nCr(int n, int r, long long kMax) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n - r) r = n - r;
        
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res = res * (n - r + i) / i;
            if (res > kMax) res = kMax;
        }
        return res;
    }

    long long countPermutations(const vector<int>& freq, long long kMax) {
        int total = 0;
        for (int f : freq) total += f;

        long long ways = 1;
        int remaining = total;
        for (int f : freq) {
            if (f > 0) {
                long long combinations = nCr(remaining, f, kMax);
                if (kMax / combinations < ways) {
                    ways = kMax;
                } else {
                    ways *= combinations;
                }
                remaining -= f;
            }
        }
        return ways;
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        int odd_count = 0;
        char middlechar = '\0';
        vector<int> half_freq(26, 0);

        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 != 0) {
                odd_count++;
                middlechar = (char)('a' + i);
            }
            half_freq[i] = freq[i] / 2;
        }

        if (odd_count > 1) return "";

        int half_len = n / 2;
        long long k_ll = k;

        if (countPermutations(half_freq, k_ll + 1) < k_ll) return "";

        string half = "";
        for (int pos = 0; pos < half_len; ++pos) {
            for (int ch = 0; ch < 26; ++ch) {
                if (half_freq[ch] == 0) continue;

                half_freq[ch]--;
                long long ways = countPermutations(half_freq, k_ll + 1);

                if (k_ll <= ways) {
                    half += (char)('a' + ch);
                    break;
                } else {
                    k_ll -= ways;
                    half_freq[ch]++;
                }
            }
        }

        string rev_half = half;
        reverse(rev_half.begin(), rev_half.end());

        if (n % 2 != 0) {
            return half + middlechar + rev_half;
        }
        return half + rev_half;
    }
};