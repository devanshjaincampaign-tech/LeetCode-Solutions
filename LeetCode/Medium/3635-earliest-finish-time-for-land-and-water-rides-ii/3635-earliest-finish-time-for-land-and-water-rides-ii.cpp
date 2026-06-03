class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int landtime=INT_MAX;
        int watertime=INT_MAX;

        for(int i=0;i<landStartTime.size();i++){
            int firstlandtime=landStartTime[i]+landDuration[i];
            landtime=min(landtime,firstlandtime);
        }

        for(int i=0;i<waterStartTime.size();i++){
            int firstwatertime=waterStartTime[i]+waterDuration[i];
            watertime=min(watertime,firstwatertime);
        }

        int totallandtime=INT_MAX;
        for(int i=0;i<waterStartTime.size();i++){
            int actualwatertime=max(landtime,waterStartTime[i]);
            totallandtime=min(totallandtime,actualwatertime+waterDuration[i]);
        }

        int totalwatertime=INT_MAX;
        for(int i=0;i<landStartTime.size();i++){
            int actuallandtime=max(watertime,landStartTime[i]);
            totalwatertime=min(totalwatertime,actuallandtime+landDuration[i]);
        }

        return min(totalwatertime,totallandtime);
    }
};