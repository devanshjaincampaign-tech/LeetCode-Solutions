class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> finalans;
        if (root == nullptr) return finalans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelsize = q.size();
            vector<int> values;

            for (int i = 0; i < levelsize; i++) {
                // Get the node from the queue and remove it
                TreeNode* current = q.front();
                q.pop();

                // Process the current node's value
                values.push_back(current->val);

                // Enqueue left and right children if they exist
                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }
            finalans.push_back(values);
        }
        return finalans;
    }
};