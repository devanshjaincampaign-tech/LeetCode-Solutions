class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> vp;
        string sp = "";

        for (char i : s) {
            if (i != ' ') {
                sp += i;
                continue;
            }
            if (!sp.empty()) {
                vp.push_back(sp);
                sp = "";
            }
        }
        if (!sp.empty()) {
            vp.push_back(sp);
        }

        if (pattern.size() != vp.size()) {
            return false;
        }

        unordered_map<char, string> mp;
        unordered_map<string, char> reverse_mp;

        for (int i = 0; i < pattern.size(); i++) {
            char g = pattern[i];
            string word = vp[i];

            if (mp.find(g) != mp.end()) {
                if (mp[g] != word) {
                    return false;
                }
            } else {
                if (reverse_mp.find(word) != reverse_mp.end()) {
                    return false;
                }
                mp[g] = word;
                reverse_mp[word] = g;
            }
        }

        return true;
    }
};