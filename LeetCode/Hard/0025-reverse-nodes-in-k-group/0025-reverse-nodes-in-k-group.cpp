class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1)
            return head;

        int count = 0;
        ListNode* curr = head;

        while (curr) {
            count++;
            curr = curr->next;
        }

        count -= (count % k);

        curr = head;
        ListNode *prev = nullptr, *next = nullptr;
        ListNode *newHead = nullptr;
        ListNode *prevTail = nullptr;

        while (count > 0) {
            ListNode* groupHead = curr;
            prev = nullptr;

            for (int i = 0; i < k; i++) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            if (!newHead)
                newHead = prev;

            if (prevTail)
                prevTail->next = prev;

            groupHead->next = curr;
            prevTail = groupHead;

            count -= k;
        }

        return newHead;
    }
};