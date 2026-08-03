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
private:
    ListNode*reverselinkedlist(ListNode*head){
        if(head==nullptr)return nullptr;
        ListNode*prev=nullptr;
        ListNode*curr=head;
        ListNode*next=nullptr;

        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        return prev;
    }
public:

    ListNode* removeNodes(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }

        head=reverselinkedlist(head);

        ListNode*temp=head;
        while(temp!=nullptr && temp->next!=nullptr){
            if(temp->val>temp->next->val){
                temp->next=temp->next->next;
            }
            else{
                temp=temp->next;
            }
        }

        head=reverselinkedlist(head);

        return head;
    }
};