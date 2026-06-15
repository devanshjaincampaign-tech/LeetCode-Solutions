class Solution {
public:
    int countSegments(string s) {
        istringstream ss(s);
        string word;
        int count = 0;
        while (ss >> word) {
            count++;
        }
        return count;
    }
};