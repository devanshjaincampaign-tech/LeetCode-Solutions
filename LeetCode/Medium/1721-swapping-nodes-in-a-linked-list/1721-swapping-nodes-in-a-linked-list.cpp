class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int count = 0;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }

        ListNode* firstNode = head;
        for (int i = 1; i < k; i++) {
            firstNode = firstNode->next;
        }

        ListNode* secondNode = head;
        for (int i = 1; i < count - k + 1; i++) {
            secondNode = secondNode->next;
        }

        swap(firstNode->val, secondNode->val);

        return head;
    }
};