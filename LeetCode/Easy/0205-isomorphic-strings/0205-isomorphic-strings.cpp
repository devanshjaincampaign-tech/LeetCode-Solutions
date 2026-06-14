class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> mapS2T;
        unordered_map<char, char> mapT2S;

        for (int i = 0; i < s.size(); i++) {
            char charS = s[i];
            char charT = t[i];

            if (mapS2T.find(charS) != mapS2T.end()) {
                if (mapS2T[charS] != charT) return false;
            } else {
                mapS2T[charS] = charT;
            }

            if (mapT2S.find(charT) != mapT2S.end()) {
                if (mapT2S[charT] != charS) return false;
            } else {
                mapT2S[charT] = charS;
            }
        }

        return true;
    }
};