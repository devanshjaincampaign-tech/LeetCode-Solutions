class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> first;
        stack<char> second;

        for (char x : s) {
            if (x == '#') {
                if (!first.empty()) first.pop();
            } else {
                first.push(x);
            }
        }

        for (char i : t) {
            if (i == '#') {
                if (!second.empty()) second.pop();
            } else {
                second.push(i);
            }
        }

        if (first.size() != second.size()) return false;

        while (!first.empty()) {
            if (first.top() != second.top()) return false;
            first.pop();
            second.pop();
        }

        return true;
    }
};