class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> stack;
        vector<int> pair(n);

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                stack.push_back(i);
            } else if (s[i] == ')') {
                int j = stack.back();
                stack.pop_back();
                pair[i] = j;
                pair[j] = i;
            }
        }

        string res = "";
        int curr = 0;
        int direction = 1;

        while (curr < n) {
            if (s[curr] == '(' || s[curr] == ')') {
                curr = pair[curr];
                direction = -direction;
            } else {
                res += s[curr];
            }
            curr += direction;
        }

        return res;
    }
};