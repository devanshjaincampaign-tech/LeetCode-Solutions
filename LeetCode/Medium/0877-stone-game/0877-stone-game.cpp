class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int evenSum = 0;
        int oddSum = 0;

        for (int i = 0; i < piles.size(); i++) {
            if (i % 2 == 0) {
                evenSum += piles[i];
            } else {
                oddSum += piles[i];
            }
        }


        return max(evenSum, oddSum) > min(evenSum, oddSum);
    }
};