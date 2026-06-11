class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int childptr=0;
        int cookieptr=0;
        while(childptr<g.size() && cookieptr<s.size()){
            if(s[cookieptr]>=g[childptr]){
                childptr++;
            }
            cookieptr++;
        }
        return childptr;
    }
};