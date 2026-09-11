class Solution {
public:
    int totalNumbers(std::vector<int>& digits) {
        int n = digits.size();
        if (n < 3) return 0;

        std::unordered_set<int> unique_even_numbers;

        for (int i = 0; i < n; i++) {
            // First digit cannot be zero (no leading zeroes)
            if (digits[i] == 0) continue;

            for (int j = 0; j < n; j++) {
                if (j == i) continue;

                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;

                    // Last digit must be even
                    if (digits[k] % 2 != 0) continue;

                    unique_even_numbers.insert(digits[i] * 100 + digits[j] * 10 + digits[k]);
                }
            }
        }

        return unique_even_numbers.size();
    }
};