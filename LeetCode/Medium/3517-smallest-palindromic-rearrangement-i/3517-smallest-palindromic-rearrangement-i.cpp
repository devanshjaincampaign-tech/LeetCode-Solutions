class Solution {
public:
    string smallestPalindrome(string s) {
        long long n = s.size();
        if (n <= 1) return s;

        string middlechar = "";
        
        if (n % 2 != 0) {
            middlechar = s[n / 2];
        }

        sort(s.begin(), s.begin() + n / 2);

        string res = "";
        for (int i = 0; i < n / 2; i++) {
            res += s[i];
        }

        string rev_res = res;
        reverse(rev_res.begin(), rev_res.end());

        if (n % 2 != 0) {
            return res + middlechar + rev_res;
        }

        return res + rev_res;
    }
};