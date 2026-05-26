#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode*next;
    ListNode(int x):val(x),next(nullptr){}
};

bool ispalindrome(ListNode* head){
    ListNode*curr=head;
    vector<int>vec;

    while(curr!=nullptr){
        int x=curr->val;
        vec.push_back(x);
        curr=curr->next;
    }

    int left=0;
    int right=vec.size()-1;
    while(left<right){
        if(vec[left]!=vec[right]){
            return false;
        }
    }
    return true;
}