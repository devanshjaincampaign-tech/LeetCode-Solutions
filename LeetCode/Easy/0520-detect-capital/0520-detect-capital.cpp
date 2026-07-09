class Solution {
public:
    bool detectCapitalUse(string word) {
        int capital_count = 0;

        for (char i : word) {
            if (isupper(i)) {
                capital_count++;
            }
        }

        if (capital_count == word.size()) {
            return true;
        }

        if (capital_count == 0) {
            return true;
        }

        if (capital_count == 1 && isupper(word[0])) {
            return true;
        }

        return false;
    }
};