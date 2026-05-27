#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode*next;

    ListNode(int x):val(x),next(nullptr){}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int>vec;
        ListNode*curr=head;
        while(curr!=nullptr){
            vec.push_back(curr->val);
            curr=curr->next;
        }
        reverse(vec.begin() + left - 1, vec.begin() + right);

        curr=head;
        int i=0;
        while(curr!=nullptr){
           curr->val=vec[i];
           i++;
           curr=curr->next;

        }
        return head;
    }
};
