#include <string>
#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    std::string removeDuplicateLetters(std::string s) {
        std::vector<int> count(26, 0);
        std::vector<bool> inStack(26, false);
        
        // Step 1: Count frequency of each character
        for (char c : s) {
            count[c - 'a']++;
        }
        
        std::stack<char> st;
        
        // Step 2: Build the result using a monotonic stack
        for (char x : s) {
            count[x - 'a']--; // Decrement remaining count
            
            // If already in the stack, skip to avoid duplicates
            if (inStack[x - 'a']) {
                continue;
            }
            
            // Pop stack top if it is strictly greater than x AND occurs later
            while (!st.empty() && x < st.top() && count[st.top() - 'a'] > 0) {
                inStack[st.top() - 'a'] = false;
                st.pop();
            }
            
            st.push(x);
            inStack[x - 'a'] = true;
        }
        
        // Step 3: Reconstruct string from stack
        std::string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        std::reverse(result.begin(), result.end());
        return result;
    }
};