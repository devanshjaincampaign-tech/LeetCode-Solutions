class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        vector<int> values;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            values.push_back(curr->val);
            curr = curr->next;
        }
        
        sort(values.begin(), values.end());
        
        curr = head; 
        
        for (int i = 0; i < values.size(); i++) {
            curr->val = values[i];
            curr = curr->next;
        }
        
        return head;
    }
};