class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int maxarea=0;
        for(int i=0;i<=n;i++){
            int curr_height=(i==n)?0:heights[i];
            while(!st.empty() && curr_height<heights[st.top()]){
                int h=heights[st.top()];
                st.pop();

                int w=st.empty()?i:(i-st.top()-1);
                maxarea=max(maxarea,h*w);
            }

            st.push(i);
        }
        return maxarea;
    }
};