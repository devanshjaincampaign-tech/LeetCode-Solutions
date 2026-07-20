class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a_count = 0;
        for (char c : s) {
            if (c == 'a') a_count++;
        }
        int b_count = s.length() - a_count;
        
        return abs(a_count - b_count);
    }
};