class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        vector<int>vp;
        for(int i=0;i<prices.size();i++){
            st.push(prices[i]);
            for(int j=i+1;j<prices.size();j++){
                if(prices[i]>=prices[j]){
                    int finalprice=st.top()-prices[j];
                    vp.push_back(finalprice);
                    st.pop();
                    break;
                }
            }
            if(!st.empty()){
                vp.push_back(st.top());
                st.pop();
            }
        }
        return vp;
    }
};