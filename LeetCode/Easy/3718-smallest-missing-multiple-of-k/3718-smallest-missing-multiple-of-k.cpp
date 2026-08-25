class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        if (k <= 0) return -1;
        
        unordered_set<int> st(nums.begin(), nums.end());
        
        
        for (long long i = 1; ; ++i) {
            long long multiple = i * k;
            if (multiple > INT_MAX) return -1; 
            
            if (st.find(static_cast<int>(multiple)) == st.end()) {
                return static_cast<int>(multiple);
            }
        }
    }
};