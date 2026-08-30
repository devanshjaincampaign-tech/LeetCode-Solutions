#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        long long minn = INT_MAX;
        long long maxx = INT_MIN;

        for (int i : nums) {
            if (i < minn) {
                minn = i;
            }
            if (i > maxx) {
                maxx = i;
            }
        }

        int min_idx = 0;
        int max_idx = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == minn) {
                min_idx = i;
            }
            if (nums[i] == maxx) {
                max_idx = i;
            }
        }

        // Identify which element comes first and which comes second
        int first = min(min_idx, max_idx);
        int second = max(min_idx, max_idx);

        // Calculate the 3 removal strategies
        int delete_from_front = second + 1;
        int delete_from_back = n - first;
        int delete_from_both = (first + 1) + (n - second);

        return min({delete_from_front, delete_from_back, delete_from_both});
    }
};