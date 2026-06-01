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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>finalans;
        if(root==nullptr) return finalans;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int levelsize=q.size();
            vector<int>ans;

            for(int i=0;i<levelsize;i++){
                
                TreeNode*current=q.front();
                ans.push_back(current->val);
                q.pop();

                if(current->left!=nullptr){
                    q.push(current->left);
                }

                if(current->right!=nullptr){
                    q.push(current->right);
                }

            }
            finalans.push_back(ans);
            
        }
        return finalans;
    }
};