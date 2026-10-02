
class Solution {
private:
    void backtrack(vector<string>& result, string& current, int open_count, int close_count, int n) {
        // Base case: a valid combination of length 2*n is formed
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add an opening parenthesis if we haven't hit the limit
        if (open_count < n) {
            current.push_back('(');
            backtrack(result, current, open_count + 1, close_count, n);
            current.pop_back(); // Backtrack
        }

        // Add a closing parenthesis if it won't create an invalid state
        if (close_count < open_count) {
            current.push_back(')');
            backtrack(result, current, open_count, close_count + 1, n);
            current.pop_back(); // Backtrack
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current = "";
        backtrack(result, current, 0, 0, n);
        return result;
    }
};