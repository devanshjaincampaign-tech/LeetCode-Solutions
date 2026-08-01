class Solution {
public:
    int findTheWinner(int n, int k) {

        queue<int>q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }

         while(q.size()>1){
                
                int steps =(k-1)%q.size();
                while(steps>0){
                    q.push(q.front());
                    q.pop();
                    steps--;
                }
                q.pop();
            }
        return q.front();
    }
};