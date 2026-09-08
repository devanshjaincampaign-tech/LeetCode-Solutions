class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> leftZeros(n, 0);
        vector<int> rightOnes(n, 0);

        // Count zeros from left to right
        leftZeros[0] = (s[0] == '0' ? 1 : 0);
        for (int i = 1; i < n; i++) {
            leftZeros[i] = leftZeros[i - 1] + (s[i] == '0' ? 1 : 0);
        }

        // Count ones from right to left
        rightOnes[n - 1] = (s[n - 1] == '1' ? 1 : 0);
        for (int i = n - 2; i >= 0; i--) {
            rightOnes[i] = rightOnes[i + 1] + (s[i] == '1' ? 1 : 0);
        }

        int answer = 0;
        // Split occurs between index i and i + 1; stop at n - 2
        for (int i = 0; i < n - 1; i++) {
            answer = max(answer, leftZeros[i] + rightOnes[i + 1]);
        }

        return answer;
    }
};