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
    void element(TreeNode*root,int k,int& result, int& count){
        if(root==nullptr || count>=k) return;
        element(root->left,k,result,count);
        count++;
        if(count==k){
            result=root->val;
            return;
        }
        element(root->right,k,result,count);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int result=-1;
        element(root,k,result,count);
        return result;
    }
};