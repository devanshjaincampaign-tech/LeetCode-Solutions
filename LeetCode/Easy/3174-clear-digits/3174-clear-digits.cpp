class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        string res="";
        for(char x:s){
            if((x>='0' && x<='9') && !st.empty()){
                st.pop();
            }
            else{
                st.push(x);
            }
        }

        while(!st.empty()){
            res+=st.top();
            st.pop();
        }

        reverse(res.begin(),res.end());
        return res;
    }
};