class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        if (k == 1) {
            for (int x : nums) {
                freq[x]++;
            }
            int largest = -1;
            for (const auto& [val, count] : freq) {
                if (count == 1 && val > largest) {
                    largest = val;
                }
            }
            return largest;
        }

        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        for (int x : nums) {
            freq[x]++;
        }

        int ans = -1;
        if (freq[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }
        if (freq[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};