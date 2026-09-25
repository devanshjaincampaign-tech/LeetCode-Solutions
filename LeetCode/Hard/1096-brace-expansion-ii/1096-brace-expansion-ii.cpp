#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        vector<unordered_set<string>> opd; // Operand stack (stores sets of strings)
        vector<char> opt;                  // Operator stack ('+', ',', '{')

        // Helper to execute top operator on operand stack
        auto evaluate = [&]() {
            char op = opt.back(); opt.pop_back();
            unordered_set<string> right = move(opd.back()); opd.pop_back();
            unordered_set<string> left = move(opd.back()); opd.pop_back();

            unordered_set<string> res;
            if (op == '+') {
                // Cartesian Product (Concatenation)
                for (const string& l : left) {
                    for (const string& r : right) {
                        res.insert(l + r);
                    }
                }
            } else if (op == ',') {
                // Union
                res = move(left);
                res.insert(right.begin(), right.end());
            }
            opd.push_back(move(res));
        };

        // Precedence: '+' (2) > ',' (1)
        auto precedence = [](char op) {
            if (op == '+') return 2;
            if (op == ',') return 1;
            return 0;
        };

        int n = expression.length();

        for (int i = 0; i < n; ++i) {
            char ch = expression[i];

            if (isalpha(ch)) {
                // Check for implicit concatenation operator (+)
                if (i > 0 && (isalpha(expression[i - 1]) || expression[i - 1] == '}')) {
                    while (!opt.empty() && opt.back() != '{' && precedence(opt.back()) >= precedence('+')) {
                        evaluate();
                    }
                    opt.push_back('+');
                }

                opd.push_back({string(1, ch)});
            } 
            else if (ch == '{') {
                // Check for implicit concatenation operator (+)
                if (i > 0 && (isalpha(expression[i - 1]) || expression[i - 1] == '}')) {
                    while (!opt.empty() && opt.back() != '{' && precedence(opt.back()) >= precedence('+')) {
                        evaluate();
                    }
                    opt.push_back('+');
                }

                opt.push_back('{');
            } 
            else if (ch == '}') {
                while (!opt.empty() && opt.back() != '{') {
                    evaluate();
                }
                opt.pop_back(); // Remove '{'
            } 
            else if (ch == ',') {
                while (!opt.empty() && opt.back() != '{' && precedence(opt.back()) >= precedence(',')) {
                    evaluate();
                }
                opt.push_back(',');
            }
        }

        // Evaluate all remaining operators
        while (!opt.empty()) {
            evaluate();
        }

        // Collect and sort the result
        vector<string> result(opd.back().begin(), opd.back().end());
        sort(result.begin(), result.end());
        return result;
    }
};