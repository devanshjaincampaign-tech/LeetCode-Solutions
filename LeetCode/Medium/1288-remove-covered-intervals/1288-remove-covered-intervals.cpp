class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || (intervals[j][0] == 0 && intervals[j][1] == 0)) {
                    continue;
                }
                
                if (intervals[i][0] >= intervals[j][0] && intervals[i][1] <= intervals[j][1]) {
                    intervals[i] = {0, 0}; 
                    break;
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (intervals[i][0] != 0 || intervals[i][1] != 0) {
                count++;
            }
        }
        
        return count;
    }
};