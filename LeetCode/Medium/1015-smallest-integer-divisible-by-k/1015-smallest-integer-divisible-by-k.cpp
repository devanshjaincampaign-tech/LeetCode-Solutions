class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // Repunits (1, 11, 111...) always end in 1.
        // They can never be divided by any even number or any number ending in 5.
        if (k % 2 == 0 || k % 5 == 0) return -1;

        int remainder = 0;
        
        // We only need to check up to k times
        for (int length = 1; length <= k; length++) {
            // Calculate the remainder of the next repunit dynamically
            remainder = (remainder * 10 + 1) % k;
            
            // If the remainder is 0, we found our smallest repunit!
            if (remainder == 0) {
                return length;
            }
        }

        return -1;
    }
};