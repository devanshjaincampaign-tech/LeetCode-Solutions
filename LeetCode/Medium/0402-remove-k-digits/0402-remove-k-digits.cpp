class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char x : num) {
            while (!st.empty() && k > 0 && st.top() > x) {
                st.pop();
                k--;
            }
            st.push(x);
        }

        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        string finalanswer = "";
        while (!st.empty()) {
            finalanswer += st.top();
            st.pop();
        }

        reverse(finalanswer.begin(), finalanswer.end());

        int start = 0;
        while (start < finalanswer.size() && finalanswer[start] == '0') {
            start++;
        }

        finalanswer = finalanswer.substr(start);

        return finalanswer.empty() ? "0" : finalanswer;
    }
};