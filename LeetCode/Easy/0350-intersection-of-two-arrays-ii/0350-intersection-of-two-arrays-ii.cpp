#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Step 1: Sort both arrays (O(N log N + M log M))
        // Skip this step if the input arrays are guaranteed to be pre-sorted
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        int i = 0; // Pointer for nums1
        int j = 0; // Pointer for nums2
        std::vector<int> result;

    
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++; 
            } else {
              
                result.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        return result;
    }
};