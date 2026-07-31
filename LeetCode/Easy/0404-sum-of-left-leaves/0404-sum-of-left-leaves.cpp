class Solution {
private:
    // Helper function to check if a node is a leaf (has no children)
    bool isLeaf(TreeNode* node) {
        return node != nullptr && node->left == nullptr && node->right == nullptr;
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;

        int sum = 0;

        // Case 1: The left child exists and IS a leaf node
        if (root->left && isLeaf(root->left)) {
            sum += root->left->val;
        } else {
            // Case 2: The left child is an internal node, recurse deeper into left subtree
            sum += sumOfLeftLeaves(root->left);
        }

        // Always recurse into the right subtree (right nodes can have left leaves!)
        sum += sumOfLeftLeaves(root->right);

        return sum;
    }
};