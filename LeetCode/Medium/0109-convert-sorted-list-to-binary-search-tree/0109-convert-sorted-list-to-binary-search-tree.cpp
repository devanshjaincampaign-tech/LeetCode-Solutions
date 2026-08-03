class Solution {
private:
    TreeNode* buildBST(ListNode* head, ListNode* tail) {
        // Base case: empty segment
        if (head == tail) return nullptr;

        // Find middle node using fast & slow pointers
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Mid node becomes current root
        TreeNode* root = new TreeNode(slow->val);

        // Recursively construct left and right subtrees
        root->left = buildBST(head, slow);
        root->right = buildBST(slow->next, tail);

        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildBST(head, nullptr);
    }
};