class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_val = nums1[0];
        bool has_odd = false;

        for (int x : nums1) {
            if (x < min_val) {
                min_val = x;
            }
            if (x % 2 != 0) {
                has_odd = true;
            }
        }

        // 1. If the minimum element is odd, we can always make all elements odd.
        // 2. If the minimum element is even, we can only succeed if all elements are even.
        return (min_val % 2 != 0) || !has_odd;
    }
};