class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int count = 0;
        string repeatedWord = word;
        
        // string::npos means "not found"
        // We keep looping as long as sequence contains our repeated word
        while (sequence.find(repeatedWord) != string::npos) {
            count++;
            repeatedWord += word; // Add another copy: "abc" -> "abcabc" -> "abcabcabc"
        }
        
        return count;
    }
};