#include <iostream>
#include <vector>
#include <stack> // Using standard stack is cleaner for this problem

using namespace std;

bool isValid(string s) {
    stack<char> st; // Stores the opening brackets
    
    for (char x : s) {
        // If it's an opening bracket, push it to the stack
        if (x == '[' || x == '{' || x == '(') {
            st.push(x);
        } 
        // If it's a closing bracket, check for validity
        else {
            // If stack is empty, it means there's no matching opening bracket
            if (st.empty()) return false;
            
            char top = st.top();
            if ((x == ']' && top == '[') ||
                (x == '}' && top == '{') ||
                (x == ')' && top == '(')) {
                st.pop(); // Matched successfully, remove from stack
            } else {
                return false; // Mismatched brackets
            }
        }
    }
    
    // If the stack is empty, all brackets were matched correctly
    return st.empty();
}

int main() {
    string s = "{[()]}";
    if (isValid(s)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }
    return 0;
}