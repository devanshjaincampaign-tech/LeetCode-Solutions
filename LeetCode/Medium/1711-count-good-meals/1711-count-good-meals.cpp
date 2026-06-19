class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> freq;
        long long count = 0;
        int mod = 1e9 + 7;

        for (int num : deliciousness) {
            
            for (int i = 0; i <= 21; i++) {
                int target = (1 << i);
                int complement = target - num;
                
                
                if (freq.count(complement)) {
                    count = (count + freq[complement]) % mod;
                }
            }
            
            freq[num]++;
        }
        
        return count;
    }
};