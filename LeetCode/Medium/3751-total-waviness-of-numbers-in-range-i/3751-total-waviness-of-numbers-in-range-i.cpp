class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int count = 0;
        while (num1 <= num2) {
            string num = to_string(num1);

           
            if (num.size() >= 3) {
                for (int i = 1; i < (int)num.size() - 1; i++) {
                    char prev = num[i-1];
                    char curr = num[i];
                    char next = num[i+1];

                
                    if (prev > curr && next > curr) {
                        count++;
                    }
                  
                    else if (prev < curr && next < curr) {
                        count++;
                    }
                }
            }
            
            num1++;
        }
        return count;
    }
};