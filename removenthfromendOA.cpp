#include <iostream>

using namespace std;

struct Listnode
{
    int val;
    Listnode*next;

    Listnode(int x):val(x),next(nullptr){}
};

class solution{
    public:
    Listnode* removenthfromend(Listnode*head,int n){
        Listnode* dummy=new Listnode(0);
        dummy->next=head;

        Listnode*fast=dummy;
        Listnode*slow=dummy;

        for(int i=0;i<n;i++){
            fast=fast->next;
        }

        while(fast->next != nullptr){
            fast=fast->next;
            slow=slow->next;
        }

        Listnode*target=slow->next;
        slow->next=target->next;
        delete target;

        Listnode*new_head=dummy->next;
        delete dummy;

        return new_head;
    }
};
