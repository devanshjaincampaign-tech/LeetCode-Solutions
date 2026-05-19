// Brute Force Approach
// Time Complexity: O(n²)
// Space Complexity: O(1)
//
// Approach:
// 1. Check every possible pair of lines.
// 2. Calculate the width between them.
// 3. Take the minimum height because water level
//    depends on the shorter line.
// 4. Compute the area.
// 5. Store the maximum area found.



#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
        int maxwater=0;
        int currentmax=0;
        for(int i=0;i<height.size();i++){
            for(int j =i+1;j<height.size();j++){
                if(height[i]<height[j]){
                    currentmax=(j-i)*height[i];
                    maxwater=max(maxwater,currentmax);
                }
                else if(height[i]>=height[j]){
                    currentmax=(j-i)*height[j];
                    maxwater=max(maxwater,currentmax);
                }
            }
        }
        return maxwater;
    }

int main(){
    vector<int> height={1,8,6,2,5,4,8,3,7};
    int maxarea=maxArea(height);

    cout<<"the max area is:"<<maxarea;
}