class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        std::vector<long long> squares;
        for (long long x : nums) {
            squares.push_back(x * x);
        }
        std::sort(squares.begin(), squares.end());
        
        long long score = 0;
        int n = squares.size();
        int negative_count = n / 2;
        
        for (int i = 0; i < negative_count; ++i) {
            score -= squares[i];
        }
        for (int i = negative_count; i < n; ++i) {
            score += squares[i];
        }
        
        return score;
    }
};