class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        
        for (int i = left; i <= right; i++) {
            int temp = i; // Use a copy so we don't destroy 'i'
            bool sd = true;
            
            while (temp > 0) {
                int digit = temp % 10;
                
                // 1. Check for 0 to prevent division-by-zero crash
                // 2. Check if the digit divides the original number 'i'
                if (digit == 0 || i % digit != 0) {
                    sd = false;
                    break; // No need to check further digits for this number
                }
                
                temp = temp / 10; // Shrink the copy
            }
            
            // If it passed all digit checks, add the original 'i'
            if (sd) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};