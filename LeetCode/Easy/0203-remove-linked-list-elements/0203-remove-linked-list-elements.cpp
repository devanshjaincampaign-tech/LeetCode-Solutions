/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        head=dummy;

        ListNode*curr=head;
        while(curr->next!=nullptr){
            if(curr->next->val==val){
                curr->next=curr->next->next;
            }
            else{
                curr=curr->next;
            }
        }

        ListNode*nextnode=head;
        head=head->next;
        delete nextnode;

        return head;
    }
};