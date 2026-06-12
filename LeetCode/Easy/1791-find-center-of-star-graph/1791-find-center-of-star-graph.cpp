class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int e = edges.size();
        int num_nodes = e + 1;
        
        
        vector<int> starnode(num_nodes + 1, 0); 
        
        for(const auto& numbers : edges){
            starnode[numbers[0]]++;
            starnode[numbers[1]]++;
        }

        
        for(int i = 1; i <= num_nodes; i++){
            if(starnode[i] == e){ 
                return i; 
            }
        }
        return -1;
    }
};