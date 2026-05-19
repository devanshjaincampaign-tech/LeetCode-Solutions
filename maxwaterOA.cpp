// Optimized Two Pointer Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
//
// Approach:
// 1. Place one pointer at the beginning
//    and one at the end.
//
// 2. Calculate the area formed by both lines.
//
// 3. Update the maximum area.
//
// 4. Move the pointer having smaller height
//    because the shorter line limits the water.
//
// 5. Continue until both pointers meet.

#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height){

    int start = 0;
    int end = height.size() - 1;

    int maxwater = 0;

    while(start < end){

        int currentwater =
            (end - start) *
            min(height[start], height[end]);

        maxwater = max(maxwater, currentwater);

        // Move the smaller height
        if(height[start] < height[end]){
            start++;
        }
        else{
            end--;
        }
    }

    return maxwater;
}

int main(){

    vector<int> height = {1,8,6,2,5,4,8,3,7};

    int maxarea = maxArea(height);

    cout << "The max area is: " << maxarea;
}