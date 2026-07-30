class Solution {
public:
    int minDepth(TreeNode* root) {
        // Base case: empty tree has depth 0
        if (root == nullptr) {
            return 0;
        }

        // If left child is null, we MUST recurse on the right subtree
        if (root->left == nullptr) {
            return 1 + minDepth(root->right);
        }

        // If right child is null, we MUST recurse on the left subtree
        if (root->right == nullptr) {
            return 1 + minDepth(root->left);
        }

        // If both children exist, take the minimum of both subtrees
        return 1 + std::min(minDepth(root->left), minDepth(root->right));
    }
};