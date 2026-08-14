class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int>charcount(26,0);

        int left=0;
        int maxlen=0;

        for(int right=0;right<s.size();right++){

            charcount[s[right]-'a']++;
            while(charcount[s[right]-'a']>2){
                charcount[s[left]-'a']--;
                left++;
            }

            maxlen=max(maxlen,right-left+1);

        }

        return maxlen;
    }
};