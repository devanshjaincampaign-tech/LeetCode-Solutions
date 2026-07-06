class Solution {
public:
    int minimumDeletions(string s) {
        int a_count = 0;
        for (char c : s) {
            if (c == 'a') a_count++;
        }
        
        int b_count = 0;
        int min_deletions = a_count; 
        
        for (char c : s) {
            if (c == 'a') {
                a_count--;
            } else {
                b_count++;
            }
            min_deletions = min(min_deletions, a_count + b_count);
        }
        
        return min_deletions;
    }
};