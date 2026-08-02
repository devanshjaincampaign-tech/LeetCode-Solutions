class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>dindex;
        queue<int>rindex;
        int n=senate.size();

        for(int i=0;i<senate.size();i++){
            if(senate[i]=='R'){
                rindex.push(i);
            }
            else{
                dindex.push(i);
            }
        }

        while(!rindex.empty() && !dindex.empty()){
            int r=rindex.front();rindex.pop();
            int d=dindex.front();dindex.pop();

            if(r>d){
                dindex.push(r+n);

            }
            else{
                rindex.push(d+n);
            }
        }
        return rindex.empty()?"Dire":"Radiant";
    }
};