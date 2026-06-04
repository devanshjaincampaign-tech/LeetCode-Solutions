#include <vector>

using namespace std;

class Solution {
private:
    int result = -1;
    int count = 0;

    void inorder(TreeNode* node, int k) {
        if (node == nullptr || count >= k) {
            return;
        }

        inorder(node->left, k);

        count++;
        if (count == k) {
            result = node->val;
            return;
        }

        inorder(node->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        result = -1;
        count = 0;
        inorder(root, k);
        return result;
    }
};