class Solution {
private:
    void findCombinations(int start_idx, int target, vector<int>& candidates, 
                          vector<int>& current_combo, vector<vector<int>>& result) {
        // Base Case 1: Target reached
        if (target == 0) {
            result.push_back(current_combo);
            return;
        }

        // Base Case 2: Target exceeded
        if (target < 0) {
            return;
        }

        // Explore choices
        for (int i = start_idx; i < candidates.size(); ++i) {
            // Include candidates[i]
            current_combo.push_back(candidates[i]);

            // Recurse: pass 'i' as start_idx because the same element can be chosen unlimited times
            findCombinations(i, target - candidates[i], candidates, current_combo, result);

            // Backtrack: remove last added element
            current_combo.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current_combo;
        
        findCombinations(0, target, candidates, current_combo, result);
        return result;
    }
};