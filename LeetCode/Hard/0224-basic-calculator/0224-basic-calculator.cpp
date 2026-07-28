class Solution {
public:
    int calculate(string s) {
        stack<long long> st;
        long long currentNumber = 0;
        long long result = 0;
        long long sign = 1;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (isdigit(ch)) {
                currentNumber = currentNumber * 10 + (ch - '0');
            } 
            else if (ch == '+') {
                result += sign * currentNumber;
                currentNumber = 0;
                sign = 1;
            } 
            else if (ch == '-') {
                result += sign * currentNumber;
                currentNumber = 0;
                sign = -1;
            } 
            else if (ch == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } 
            else if (ch == ')') {
                result += sign * currentNumber;
                currentNumber = 0;

                long long prevSign = st.top(); st.pop();
                long long prevResult = st.top(); st.pop();

                result = prevResult + (prevSign * result);
            }
        }

        result += sign * currentNumber;

        return (int)result;
    }
};