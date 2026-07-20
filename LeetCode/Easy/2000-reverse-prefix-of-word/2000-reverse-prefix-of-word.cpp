class Solution {
public:
    string reversePrefix(string word, char ch) {
        int pos=word.find(ch);
        if(pos==-1) return word;
        int left=0;
        while(left<=pos){
            swap(word[left],word[pos]);
            left++;
            pos--;
        }
        return word;
    }
};