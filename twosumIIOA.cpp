// Optimal Approach for LeetCode 167: Two Sum II - Input Array Is Sorted
// Time Complexity: O(n)
// Space Complexity: O(1)
//
// Approach:
// Since the array is already sorted, we can use the Two Pointer technique.
//
// 1. Initialize two pointers:
//    - left  -> starting index
//    - right -> ending index
//
// 2. Calculate the sum of elements at both pointers.
//
// 3. If the sum equals the target:
//    return the 1-based indices.
//
// 4. If the sum is smaller than the target:
//    move the left pointer forward to increase the sum.
//
// 5. If the sum is greater than the target:
//    move the right pointer backward to decrease the sum.
//
// This approach avoids checking every pair and reduces
// the time complexity from O(n^2) to O(n).

#include <iostream>
#include <vector>

using namespace std;
vector<int> twoSum(vector<int>& numbers, int target){
    int start=0;
    int end=numbers.size()-1;
    int sum=0;
    while(start<end){
        if(numbers[start]+numbers[end]==target){
            return {start+1,end+1};
        }
        else if(numbers[start]+numbers[end]>target){
            end--;
        }
        else if(numbers[start]+numbers[end]<target){
            start++;
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