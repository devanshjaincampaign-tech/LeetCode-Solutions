class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string, bool> stringmap;
        int n = word.size(); // Store as int to avoid unsigned underflow bugs
        
        for(int i = 0; i < n; i++){
            // Bug fix: Changed '<' to '<=' to include the last characters/full substrings
            for(int len = 1; len <= n - i; len++){
                stringmap[word.substr(i, len)] = true;
            }
        }
        
        int count = 0;
        for(string s : patterns){
            if(stringmap.find(s) != stringmap.end()){
                count++;
            }
        }
        return count;
    }
};