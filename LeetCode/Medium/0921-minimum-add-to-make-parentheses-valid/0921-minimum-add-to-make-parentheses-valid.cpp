class Solution {
public:
    int minAddToMakeValid(string s) {
        int openpara=0,closepara=0;
        for(char x:s){
            if(x=='('){
                openpara++;
            }
            else if(x==')' && openpara>0){
                openpara--;
            }
            else{
                closepara++;
            }
        }
        return closepara+openpara;
    }
};