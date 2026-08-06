class Solution {
private:
    void dfs(vector<vector<char>>&grid, int r, int c){
        int row=grid.size();
        int col=grid[0].size();

        if(r<0||r>=row ||c<0||c>=col|| grid[r][c] == '0')return;

        grid[r][c]='0';

        dfs(grid,r+1,c);
        dfs(grid,r-1,c);
        dfs(grid,r,c+1);
        dfs(grid,r,c-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())return 0;
        int islandcount=0;

        int row=grid.size();
        int col=grid[0].size();

        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(grid[r][c]=='1'){
                    islandcount++;
                    dfs(grid,r,c);
                }
            }
        }
        return islandcount;
    }
};