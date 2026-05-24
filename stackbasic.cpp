#include <iostream>
#include <vector>
#include <algorithm> // For std::reverse

class Stack {
private:
    // We use a vector internally to store items
    // The END of the vector = the TOP of the stack
    std::vector<int> items;

public:
    // Add item to the top
    void push(int item) {
        items.push_back(item);
    }

    // Remove item from the top and return it
    // Using a pointer or a special value since C++ requires a fixed return type.
    // We'll return -1 or handle it via console if empty, or use a nullable approach.
    // For simplicity and matching your `null` logic, we will return -1 if empty.
    int pop() {
        // Check if stack is empty before removing
        if (isEmpty()) {
            std::cout << "Stack Underflow! ";
            return -1; // nothing to remove
        }
        int topItem = items.back();
        items.pop_back();
        return topItem;
    }

    // Look at the top item without removing it
    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty! ";
            return -1;
        }
        // Last element in vector = top of stack
        return items.back();
    }

    // Check if stack has no items
    bool isEmpty() {
        return items.empty();
    }

    // How many items in the stack
    int size() {
        return items.size();
    }

    // See all items (for debugging)
    void print() {
        std::cout << "Stack (top -> bottom): [";
        // Create a copy to reverse and print, matching the JS behavior
        std::vector<int> copy = items;
        std::reverse(copy.begin(), copy.end());
        
        for (size_t i = 0; i < copy.size(); ++i) {
            std::cout << copy[i];
            if (i < copy.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";
    }
};

// ─────────────────────────────────
// TEST YOUR STACK
// ─────────────────────────────────
int main() {
    Stack stack;

    std::cout << std::boolalpha; // Prints true/false instead of 1/0
    std::cout << "Is empty? " << stack.isEmpty() << "\n"; // true

    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.print(); // [8, 3, 5]

    std::cout << "Peek: " << stack.peek() << "\n"; // 8 — top item
    std::cout << "Pop: " << stack.pop() << "\n";   // 8 — removed
    std::cout << "Pop: " << stack.pop() << "\n";   // 3 — removed
    stack.print(); // [5]

    std::cout << "Size: " << stack.size() << "\n"; // 1

    return 0;
}