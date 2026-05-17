//This is the Brute-force approach for the LEETCODE PROBLEM-1 TWO SUM
//The time complexity for this approach is O(n^2)
//The space complexity for this approach is O(1)

#include <iostream>
#include <vector>

using namespace std;

vector<int> twosum(vector<int>& nums, int target){
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]+nums[j]==target)
            return {i,j};
        }
    }
    return {};
}

/* In the Above function there is a loop inside a loop and we try to
find the sum one by one for every index and then try to find the pair of index
on which the sum of the value is equal to the target value*/

int main(){
    vector<int> nums={2,7,11,15};
    int target=9;

    vector<int> ans= twosum(nums, target);
    cout<<ans[0]<<" "<<ans[1];
}