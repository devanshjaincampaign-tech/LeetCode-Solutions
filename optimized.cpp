//This is the optimized approach which uses hashing method to solve the problem
/*Hashing is a technique used to store and retrieve data quickly by 
converting a key into a fixed index using a hash function, 
enabling operations like search, insertion, and deletion in 
approximately O(1) time on average.*/

//To solve this code we are going to use unordered_map

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int,int> mp;

    for(int i=0;i<nums.size();i++){
        int complement = target=nums[i];
        /*Above we have taken the complement by subtracting the target
        value from every value at index i, and then we try to find that
        value in our unordered_map, if we find it we return the indices
        else we add the complement value in the unordere_map for future
        prefreneces */

        if(mp.find(complement)!=mp.end()){
            return {mp[complement],i};
        }
        /* here we have added the index oof unordered_map as the
        value and the value as the index of the value*/
        mp[nums[i]]=i;
    }

    return{};
}

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector<int> ans = twoSum(nums, target);

    cout << ans[0] << " " << ans[1];
}

/* the time complexity using the optimized approach decreases to O(n) 
and the space complexity is O(n)*/