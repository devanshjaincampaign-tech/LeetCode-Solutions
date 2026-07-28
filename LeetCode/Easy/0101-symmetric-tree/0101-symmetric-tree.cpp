class Solution {
private:
    bool isMirror(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr || p->val != q->val) return false;
        
        return isMirror(p->left, q->right) && isMirror(p->right, q->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isMirror(root->left, root->right);
    }
};