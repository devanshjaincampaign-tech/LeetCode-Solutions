class Solution {
private: 
    int atMostK(const vector<int>&nums,int k){
        if(k<0)return 0;
        int left=0,right=0;
        int count=0;
        unordered_map<int,int>freq;
        while(right<nums.size()){
            freq[nums[right]]++;

            while(freq.size()>k){
                freq[nums[left]]--;
                if(freq[nums[left]]==0){
                    freq.erase(nums[left]);
                }
                left++;
            }
            count+=right-left+1;
            right++;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums,k)-atMostK(nums,k-1);
    }
};