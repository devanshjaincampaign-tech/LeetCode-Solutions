class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>intersectionvalues;
        int n=nums1.size();
        int m=nums2.size();

        unordered_map<int,bool>mp;

        for(int i:nums1){
            mp[i]=true;
        }

        for(int i:nums2){
            if(mp[i]==true){
                intersectionvalues.push_back(i);
                mp[i]=false;
            }
        }

        return intersectionvalues;
    }
};