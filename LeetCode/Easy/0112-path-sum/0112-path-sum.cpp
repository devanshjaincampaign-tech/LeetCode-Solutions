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
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr){
            return false;
        }   
        stack<pair<TreeNode*,int>>st;
        st.push({root,root->val});

        while(!st.empty()){
            auto [currentnode,currentsum]=st.top();
            st.pop();
            if(currentnode->left==nullptr && currentnode->right==nullptr){
                if(currentsum==targetSum){
                    return true;
                }
            }

            if(currentnode->right!=nullptr){
                st.push({currentnode->right,currentsum+currentnode->right->val});
            }

            if(currentnode->left!=nullptr){
                st.push({currentnode->left,currentsum+currentnode->left->val});
            }
        }
        return false;
    }   
};