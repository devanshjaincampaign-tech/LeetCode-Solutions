class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count=0;
        for(string x:logs){
            if(x=="../" ){
                if(count>0){
                    count--;
                }
                
            }
            else if(x=="./"){
                continue;
            }
            else{
                count++;
            }
        }
        return count;
    }
};