

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Step 1: Edge cases
        if (!head || !head->next || k == 0) return head;
        
        // Step 2 & 3: Compute length and find the actual tail
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }
        
        k = k % length;
        if (k == 0) return head; // No rotation needed
        
        // Step 4: Connect tail to head to form a circle
        tail->next = head;
        
        // Step 5: Find the new tail node
        // It is located at (length - k) steps from the current head
        ListNode* new_tail = head;
        for (int i = 1; i < length - k; i++) {
            new_tail = new_tail->next;
        }
        
        // Step 6: Break the ring
        ListNode* new_head = new_tail->next;
        new_tail->next = nullptr;
        
        return new_head;
    }
};