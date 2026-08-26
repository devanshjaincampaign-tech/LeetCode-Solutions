class Solution {
public:
    std::string shortestBeautifulSubstring(std::string s, int k) {
        int n = s.size();
        std::string ans = "";
        int l = 0, ones = 0;

        for (int r = 0; r < n; ++r) {
            if (s[r] == '1') {
                ones++;
            }

            while (ones == k) {
                while (s[l] == '0') {
                    l++;
                }

                std::string candidate = s.substr(l, r - l + 1);

                if (ans.empty() || candidate.size() < ans.size() || 
                   (candidate.size() == ans.size() && candidate < ans)) {
                    ans = candidate;
                }

                if (s[l] == '1') {
                    ones--;
                }
                l++;
            }
        }

        return ans;
    }
};