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
    TreeNode*Minvaluenode(TreeNode*root){
        TreeNode*curr=root;
        while(curr!=nullptr && curr->left!=nullptr){
            curr=curr->left;
        }

        return curr;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)return nullptr;
        TreeNode*current=root;

        if(current->val>key){
            root->left= deleteNode(current->left, key);
        }

        else if(current->val<key){
            root->right= deleteNode(current->right,key);
        }
        else{
            if(current->left==nullptr){
                TreeNode*temp=root->right;
                delete current;
                return temp;
            }
            else if(current->right==nullptr){
                TreeNode*temp=root->left;
                delete current;
                return temp;
            }
            else{
                TreeNode*temp=Minvaluenode(current->right);
                current->val=temp->val;
                current->right=deleteNode(root->right,temp->val);
                
            }
        }
        return current;
    }
};