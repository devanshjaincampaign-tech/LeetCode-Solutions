class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highestaltitude=INT_MIN;
        int currentheight=0;
        for(int i=0;i<gain.size();i++){
            currentheight=currentheight+gain[i];
            highestaltitude=max(highestaltitude,currentheight);
        }
        if(highestaltitude<0)return 0;
        return highestaltitude;
    }
};