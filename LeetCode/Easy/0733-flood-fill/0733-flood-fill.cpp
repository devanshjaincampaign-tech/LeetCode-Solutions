class Solution {
void colorfill(vector<vector<int>>& image, int r,int c,int newcolor, int oldcolor){
    int rows=image.size();
    int cols=image[0].size();

    if(r<0 || r>=rows || c<0 || c>=cols)return ;
    if(image[r][c]!=oldcolor || image[r][c]==newcolor)return ;


    image[r][c]=newcolor;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    for (int d = 0; d < 4; d++) {
        colorfill(image, r + dr[d], c + dc[d], newcolor, oldcolor);
    }


}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor=image[sr][sc];

        int rows=image.size();
        int cols=image[0].size();

        if (oldcolor != color) {
            colorfill(image, sr, sc, color, oldcolor);
        }

        return image;
    }
};