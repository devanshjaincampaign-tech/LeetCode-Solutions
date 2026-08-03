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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        if(head==nullptr)return nullptr;
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        head=dummy;


        unordered_set<int>st;
        for(int i:nums){
            st.insert(i);
        }

        ListNode*temp=head;
        while(temp->next!=nullptr){
            if(st.find(temp->next->val)!=st.end()){
                temp->next=temp->next->next;
                
            }
            else{
                temp=temp->next;
            }
        }
        ListNode*curr=head;
        head=head->next;
        delete curr;

        return head;
    }
};