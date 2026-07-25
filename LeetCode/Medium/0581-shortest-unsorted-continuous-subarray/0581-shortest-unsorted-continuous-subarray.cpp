class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int left = n, right = -1;

    
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                left = min(left, st.top());
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

    
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                right = max(right, st.top());
                st.pop();
            }
            st.push(i);
        }

        return right - left > 0 ? right - left + 1 : 0;
    }
};