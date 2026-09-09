class Solution {
public:
    long long countCommas(long long n) {
        long long total_commas = 0;
        
        for (long long threshold = 1000; n >= threshold; ) {
            total_commas += (n - threshold + 1);
            
            if (threshold > LLONG_MAX / 1000) {
                break; 
            }
            threshold *= 1000;
        }
        
        return total_commas;
    }
};
