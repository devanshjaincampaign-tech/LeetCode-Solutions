#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs){

    // Store sorted versions
    vector<string> sortedArr = strs;

    // Sort every string in sortedArr
    for(int i=0; i<sortedArr.size(); i++){
        sort(sortedArr[i].begin(), sortedArr[i].end());
    }

    vector<vector<string>> ans;

    // To avoid repeating groups
    vector<bool> visited(strs.size(), false);

    // Traverse every element
    for(int i=0; i<strs.size(); i++){

        // Skip already grouped elements
        if(visited[i]){
            continue;
        }

        vector<string> temp;

        // Add current original string
        temp.push_back(strs[i]);

        visited[i] = true;

        // Compare with remaining strings
        for(int j=i+1; j<strs.size(); j++){

            // If sorted versions are same
            if(sortedArr[i] == sortedArr[j]){

                temp.push_back(strs[j]);

                visited[j] = true;
            }
        }

        // Push current group into answer
        ans.push_back(temp);
    }

    return ans;
}

int main(){

    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> result = groupAnagrams(strs);

    // Print result
    for(auto group : result){

        cout << "[ ";

        for(auto word : group){
            cout << word << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}