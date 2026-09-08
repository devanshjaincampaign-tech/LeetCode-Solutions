class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int running_sum = 0;
        int min_sum = 0;

        for (int x : nums) {
            running_sum += x;
            min_sum = min(min_sum, running_sum);
        }

        return 1 - min_sum;
    }
};