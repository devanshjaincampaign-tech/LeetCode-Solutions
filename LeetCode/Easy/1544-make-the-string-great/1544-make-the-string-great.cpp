class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        
        for (char x : s) {
            
            if (!st.empty() && abs(x - st.top()) == 32) {
                st.pop();
            } else {
                st.push(x);
            }
        }

        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};