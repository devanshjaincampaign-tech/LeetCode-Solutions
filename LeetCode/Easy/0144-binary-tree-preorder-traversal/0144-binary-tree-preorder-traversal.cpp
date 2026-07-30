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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>finalans;

        TreeNode*curr=root;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                finalans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode*pred=curr->left;
                while(pred->right!=nullptr && pred->right!=curr){
                    pred=pred->right;
                }

                if(pred->right==nullptr){
                    pred->right=curr;
                    finalans.push_back(curr->val);
                    curr=curr->left;
                }
                else{
                    pred->right=nullptr;
                    
                    curr=curr->right;
                }
            }
        }
        return finalans;
    }
};