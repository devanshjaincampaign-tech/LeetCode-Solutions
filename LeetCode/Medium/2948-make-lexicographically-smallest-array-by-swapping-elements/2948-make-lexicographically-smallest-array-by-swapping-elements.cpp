class Solution {
public:
    std::vector<int> lexicographicallySmallestArray(std::vector<int>& nums, int limit) {
        int n = nums.size();
        
        // Store value along with its original index
        std::vector<std::pair<int, int>> sortedPairs(n);
        for (int i = 0; i < n; ++i) {
            sortedPairs[i] = {nums[i], i};
        }
        
        // Sort pairs primarily by value
        std::sort(sortedPairs.begin(), sortedPairs.end());
        
        std::vector<int> result(n);
        int i = 0;
        
        while (i < n) {
            int j = i + 1;
            // Find the boundary of the current connected component
            while (j < n && sortedPairs[j].first - sortedPairs[j - 1].first <= limit) {
                ++j;
            }
            
            // Extract the original indices of this component
            std::vector<int> indices;
            indices.reserve(j - i);
            for (int k = i; k < j; ++k) {
                indices.push_back(sortedPairs[k].second);
            }
            
            // Sort indices so smaller values get assigned to earlier positions
            std::sort(indices.begin(), indices.end());
            
            // Assign the sorted values to the sorted positions
            for (int k = 0; k < indices.size(); ++k) {
                result[indices[k]] = sortedPairs[i + k].first;
            }
            
            i = j;
        }
        
        return result;
    }
};