class Solution {
public:
    string addStrings(string num1, string num2) {
        string finalsum = "";
        
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;

        // Loop from the back of both strings until both are exhausted
        while (i >= 0 || j >= 0 || carry != 0) {
            int number1 = 0;
            int number2 = 0;

            if (i >= 0) {
                number1 = num1[i] - '0';
                i--;
            }
            if (j >= 0) {
                number2 = num2[j] - '0';
                j--;
            }

            int y = number1 + number2 + carry;
            finalsum = finalsum + to_string(y % 10);
            carry = y / 10;
        }

        // std::reverse returns void, so reverse first, then return
        reverse(finalsum.begin(), finalsum.end());
        return finalsum;
    }
};