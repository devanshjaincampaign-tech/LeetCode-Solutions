#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<pair<int, int>, int>> arr(n);
        
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int sum = 0;
            while (x != 0) {
                sum = sum + (x % 10);
                x /= 10; 
            }
         
            arr[i] = {{sum, nums[i]}, i};
        }
        
        sort(arr.begin(), arr.end());
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || arr[i].second == i) {
                continue;
            }

            int cycle_size = 0;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = arr[curr].second;
                cycle_size++;
            }

            if (cycle_size > 1) {
                swaps += cycle_size - 1;
            }
        }
        
        return swaps;
    }
};