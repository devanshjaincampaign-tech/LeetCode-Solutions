class Solution {
private:
    void inorder(TreeNode* root, vector<int>& memo) {
        if (root == nullptr) return;
        inorder(root->left, memo);
        memo.push_back(root->val);
        inorder(root->right, memo);
    }

public:
    vector<int> findMode(TreeNode* root) {
        vector<int> memo;
        inorder(root, memo);

        unordered_map<int, int> mp;
        int maxFreq = 0;

      
        for (int val : memo) {
            mp[val]++;
            maxFreq = max(maxFreq, mp[val]);
        }

        
        vector<int> modes;
        for (auto& pair : mp) {
            if (pair.second == maxFreq) {
                modes.push_back(pair.first);
            }
        }

        return modes;
    }
};