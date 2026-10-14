class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }
        
        std::string result = "";
        int nines = sum / 9;
        int remainder = sum % 9;
        
        for (int i = 0; i < nines; ++i) {
            result += '9';
        }
        
        if (remainder > 0) {
            result += std::to_string(remainder);
        }
        
        while (result.length() < num) {
            result += '0';
        }
        
        return result;
    }
};