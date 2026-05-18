/// Brute Force Approach for LeetCode 167: Two Sum II - Input Array Is Sorted
// Time Complexity: O(n^2)
// Space Complexity: O(1)
//
// Approach:
// Use two nested loops to check every possible pair
// in the array.
//
// 1. Traverse the array using the first loop.
//
// 2. For every element, use a second loop to check
//    all elements ahead of the current index.
//
// 3. If the sum of both elements equals the target,
//    return their 1-based indices.
//
// 4. If no valid pair exists, return an empty vector.
//
// This approach is simple and easy to understand,
// but it is not efficient for large inputs because
// every pair is checked manually.

#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>&numbers, int target){
    for(int i=0;i<numbers.size();i++){
        for(int j=i+1;j<numbers.size();j++){
            if(numbers[i]+numbers[j]==target){
                return {i+1,j+1};
            }
        }
    }
    return {};
}

int main() {

    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(numbers, target);

    if(!result.empty()) {

        cout << "Indices: ";

        for(int index : result) {
            cout << index << " ";
        }

        cout << endl;

    } else {

        cout << "No valid pair found." << endl;
    }

    return 0;
}