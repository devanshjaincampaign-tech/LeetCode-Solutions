#include <iostream>

using namespace std;

struct Listnode
{
    int val;
    Listnode* next;
    Listnode(int x):val(x),next(nullptr){}
};

class solution {
public:
    Listnode* removenthfromend(Listnode* head, int n) {
        int count = 0;
        Listnode* curr = head;
        
        // Step 1: Count the total number of nodes
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        
        // Find the index of the node to remove (0-indexed)
        int pos = count - n;
        
        // Edge Case: If we need to remove the head node
        if (pos == 0) {
            Listnode* temp = head;
            head = head->next; // Move head to the next node
            delete temp;       // Free the old head memory
            return head;
        }
        
        // Step 2: Reset curr to the start of the list
        curr = head;
        
        // Step 3: Stop at the node right BEFORE the target node
        // We go up to pos - 1
        for (int i = 0; i < pos - 1; i++) {
            curr = curr->next;
        }
        
        // Step 4: Disconnect the target node and delete it
        Listnode* target = curr->next;   // The node to be deleted
        curr->next = target->next;       // Bypass the target node
        delete target;                   // Free the memory
        
        return head;
    }
};