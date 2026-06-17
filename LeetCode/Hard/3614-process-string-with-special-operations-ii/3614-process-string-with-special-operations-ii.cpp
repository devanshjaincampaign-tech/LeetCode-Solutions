class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> lengths(n, 0);
        long long curr_len = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] != '*' && s[i] != '#' && s[i] != '%') {
                curr_len++;
            } else if (s[i] == '*') {
                if (curr_len > 0) curr_len--;
            } else if (s[i] == '#') {
                curr_len *= 2;
            } else if (s[i] == '%') {
                
            }
            lengths[i] = curr_len;
        }

        if (k < 0 || k >= curr_len) return '.';

        for (int i = n - 1; i >= 0; --i) {
            long long prev_len = (i > 0) ? lengths[i - 1] : 0;

            if (s[i] != '*' && s[i] != '#' && s[i] != '%') {
                if (k == lengths[i] - 1) {
                    return s[i];
                }
            } else if (s[i] == '#') {
                if (k >= prev_len) {
                    k %= prev_len;
                }
            } else if (s[i] == '%') {
                k = (lengths[i] - 1) - k;
            }
        }

        return '.';
    }
};