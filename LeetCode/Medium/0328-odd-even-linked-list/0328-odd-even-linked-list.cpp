class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* firsteven = head->next;
        
        int count = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }

        curr = head;
        for (int i = 1; i <= count && curr != nullptr; i++) {
            ListNode* nextNode = curr->next;
            
            if (i == 1 || i == 2) {
                curr = nextNode;
                continue;
            }
            
            if (i % 2 != 0) {
                odd->next = curr;
                odd = odd->next;
            } else {
                even->next = curr;
                even = even->next;
            }
            
            curr = nextNode;
        }

        even->next = nullptr;
        odd->next = firsteven;

        return head;
    }
};