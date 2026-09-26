class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (const auto& kv : knowledge) {
            mp[kv[0]] = kv[1];
        }

        string result = "";
        string key = "";
        bool in_bracket = false;

        for (char c : s) {
            if (c == '(') {
                in_bracket = true;
            } else if (c == ')') {
                in_bracket = false;
                if (mp.count(key)) {
                    result += mp[key];
                } else {
                    result += "?";
                }
                key = "";
            } else if (in_bracket) {
                key += c;
            } else {
                result += c;
            }
        }

        return result;
    }
};