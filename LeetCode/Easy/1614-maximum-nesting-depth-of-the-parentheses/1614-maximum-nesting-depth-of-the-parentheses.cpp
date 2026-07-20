class Solution {
public:
    int maxDepth(string s) {

        if(s.empty())return 0;
        int currcount=0;
        int maxcount=0;

        for(char x:s){
            if(x=='('){
                ++currcount;
            }
            else if(x==')'){
                maxcount=max(currcount,maxcount);
                currcount--;
                
            }
            else{
                continue;
            }
        }
        return maxcount; 
    }
};