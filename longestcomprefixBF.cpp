#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestcommonPrefix(vector<string>& strs) {
    // Edge case: if the vector is empty, return an empty string
    if (strs.empty()) return "";

    string result = "";
    
    // Loop through each character of the first string
    for (int i = 0; i < strs[0].size(); i++) {
        char ch = strs[0][i];

        // Check this character against the same position in all other strings
        for (int j = 1; j < strs.size(); j++) {
            // Bug prevention: If 'i' reaches the end of any string, 
            // or if the characters don't match, we are done.
            if (i >= strs[j].size() || strs[j][i] != ch) {
                return result;
            }
        }
        
        // If everyone matched, add this character to our prefix
        result.push_back(ch);
    }
    
    return result;
}

int main() {
    // Note: Removed the stray comma inside "flow," from your original test case
    vector<string> strs = {"flower", "flow", "floor"}; 
    string prefix = longestcommonPrefix(strs);

    cout << "The longest common prefix is: " << prefix << endl;
    return 0;
}