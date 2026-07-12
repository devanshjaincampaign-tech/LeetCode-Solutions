class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>copy(arr.size());
        for(int i=0;i<arr.size();i++){
            copy[i]=arr[i];
        }
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        int count=1;
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i])!=mp.end()){
                continue;
            }
            mp[arr[i]]=count;
            count++;
        }

        for(int i=0;i<arr.size();i++){
            arr[i]=mp[copy[i]];
        }
        return arr;
    }
};