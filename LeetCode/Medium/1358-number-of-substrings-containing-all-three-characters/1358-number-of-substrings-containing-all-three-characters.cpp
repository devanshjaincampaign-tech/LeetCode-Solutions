class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> counts(3, 0);
        int left = 0;
        int count = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            counts[s[right] - 'a']++;
            
            while (counts[0] > 0 && counts[1] > 0 && counts[2] > 0) {
                counts[s[left] - 'a']--;
                left++;
            }
            
            count += left;
        }
        
        return count;
    }
};