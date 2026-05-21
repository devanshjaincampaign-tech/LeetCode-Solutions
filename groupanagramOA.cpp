#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

 vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        
        for(string x: strs){
            string temp=x;

            sort(x.begin(),x.end());
            mp[temp].push_back(x);
        }
        vector<vector<string>>ans;

        for(auto& group:mp){
            ans.push_back(group.second);
        }
       

}