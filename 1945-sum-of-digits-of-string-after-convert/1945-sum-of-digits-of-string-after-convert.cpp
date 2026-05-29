class Solution {
public:
    int getLucky(string s, int k) {
        int current_sum = 0;
        
        // Step 1: Convert string characters to numbers and sum their digits
        for(char x : s){
            int a = x - 'a' + 1;
            while(a != 0){
                current_sum += a % 10;
                a /= 10;
            }
        }
        
        // Step 2: Perform the remaining (k - 1) transformations
        // We do k - 1 because the string loop above already counts as the 1st transform
        for(int i = 1; i < k; i++) {
            int temp_sum = 0;
            while(current_sum != 0) {
                temp_sum += current_sum % 10;
                current_sum /= 10;
            }
            current_sum = temp_sum; // Feed the new sum back into current_sum for the next round
        }
        
        return current_sum;
    }
};