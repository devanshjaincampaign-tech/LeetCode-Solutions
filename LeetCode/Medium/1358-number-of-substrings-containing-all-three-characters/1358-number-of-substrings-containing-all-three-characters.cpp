class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> last_seen(3, -1);
        int count = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            last_seen[s[i] - 'a'] = i;
            
            if (last_seen[0] != -1 && last_seen[1] != -1 && last_seen[2] != -1) {
                count += min({last_seen[0], last_seen[1], last_seen[2]}) + 1;
            }
        }
        
        return count;
    }
};