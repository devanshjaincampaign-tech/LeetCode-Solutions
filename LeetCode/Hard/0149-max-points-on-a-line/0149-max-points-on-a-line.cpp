class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        
        int max_points = 0;
        
        for (int i = 0; i < n; i++) {
            unordered_map<string, int> slope_map;
            int local_max = 0;
            
            for (int j = i + 1; j < n; j++) {
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];
                
                int g = gcd(dy, dx);
                dy /= g;
                dx /= g;
                
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    dy = 1;
                }
                
                string slope = to_string(dy) + "/" + to_string(dx);
                slope_map[slope]++;
                local_max = max(local_max, slope_map[slope]);
            }
            
            max_points = max(max_points, local_max + 1);
        }
        
        return max_points;
    }
};