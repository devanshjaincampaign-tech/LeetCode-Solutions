#include <stack>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<int> s1;
        std::stack<int> s2;

        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* head = nullptr;
        int carry = 0;

        while (!s1.empty() || !s2.empty() || carry != 0) {
            int sum = carry;

            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }

            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            carry = sum / 10;

            ListNode* newNode = new ListNode(sum % 10);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};