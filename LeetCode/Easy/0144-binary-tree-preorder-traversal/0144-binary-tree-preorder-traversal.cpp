/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void preorder(TreeNode*root, vector<int>&pre){
        if(root==nullptr){
            return;
        }

        pre.push_back(root->val);
        preorder(root->left,pre);
        preorder(root->right,pre);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>pre;
        preorder(root,pre);
        return pre;
    }
};