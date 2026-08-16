class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};
        for (int stone : stones) {
            cnt[stone % 3]++;
        }

        if (cnt[0] % 2 == 0) {
            return cnt[1] >= 1 && cnt[2] >= 1;
        } else {
            return std::abs(cnt[1] - cnt[2]) > 2;
        }
    }
};