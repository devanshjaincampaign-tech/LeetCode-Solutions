class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* curr2 = head->next;

        while (curr2 != nullptr) {
            int sum = 0;

            while (curr2->next != nullptr && curr2->val != 0) {
                sum += curr2->val;
                curr2 = curr2->next;
            }

            curr->val = sum;

            curr2 = curr2->next;
            curr->next = curr2;

            curr = curr->next;
        }

        return head->next;
    }
};