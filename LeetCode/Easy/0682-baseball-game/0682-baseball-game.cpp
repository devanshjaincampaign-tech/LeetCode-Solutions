class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        
        for (string i : operations) {
            if (i == "C") {
                if (!st.empty()) {
                    st.pop();
                }
            } 
            else if (i == "D") {
                if (!st.empty()) {
                    st.push(st.top() * 2);
                }
            } 
            else if (i == "+") {
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                
                st.push(top1);
                st.push(top1 + top2);
            } 
            else {
                st.push(stoi(i));
            }
        }
        
        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        
        return sum;
    }
};