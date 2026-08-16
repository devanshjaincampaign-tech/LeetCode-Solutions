class Solution {
public:
    string longestNiceSubstring(string s) {
        if (s.length() < 2) return "";

        unordered_set<char> char_set(s.begin(), s.end());

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (char_set.count(tolower(c)) && char_set.count(toupper(c))) {
                continue;
            }

            string left = longestNiceSubstring(s.substr(0, i));
            string right = longestNiceSubstring(s.substr(i + 1));

            return (right.length() > left.length()) ? right : left;
        }

        return s;
    }
};