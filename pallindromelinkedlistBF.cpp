#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct ListNode{
    int val;
    ListNode*next;

    ListNode(int x):val(x),next(nullptr){}
};

bool ispalindrome(ListNode*head){
    ListNode*curr=head;
    int n=0;
    while(curr!=nullptr){
        n=n*10+curr->val;
        curr=curr->next;
    }
    int a=n;
    string s=to_string(n);
    reverse(s.begin(),s.end());

    int x=stoi(s);

    if(a==x){
        return true;
    }
    return false;
}