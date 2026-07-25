class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int num2 = INT_MIN;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < num2) {
                return true;
            }

            while (!st.empty() && st.top() < nums[i]) {
                num2 = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};