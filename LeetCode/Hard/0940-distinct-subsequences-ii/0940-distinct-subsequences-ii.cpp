class Solution {
public:
    int distinctSubseqII(std::string s) {
        const int MOD = 1'000'000'007;
        
        // endsWith[i] stores the number of distinct subsequences ending with ('a' + i)
        std::vector<long long> endsWith(26, 0);
        long long total = 0; // Running total of all distinct subsequences

        for (char c : s) {
            int idx = c - 'a';
            
            // New distinct subsequences ending in 'c':
            // 1 (the single character 'c') + all currently existing subsequences
            long long newCount = (1 + total) % MOD;
            
            // Update total: subtract the previous count for this character and add newCount
            total = (total - endsWith[idx] + newCount) % MOD;
            if (total < 0) {
                total += MOD; // Handle negative modulo in C++
            }
            
            endsWith[idx] = newCount;
        }

        return total;
    }
};