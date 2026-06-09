class Solution {
private:
    bool canShipwithcapacity(vector<int>& weights, int days, int maxCapacity){
        int daysneeded = 1;
        int currentweightsum = 0;

        for(int weight : weights){
            if(currentweightsum + weight > maxCapacity){
                daysneeded++;
                currentweightsum = weight;

                if(daysneeded > days){
                    return false;
                }
            }
            else{
                currentweightsum += weight;
            }
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // 1. Added '*' to dereference the iterator
        int low = *max_element(weights.begin(), weights.end()); 
        
        // 2. Fixed 'weight.end()' typo to 'weights.end()'
        int high = accumulate(weights.begin(), weights.end(), 0); 

        // 3. Made the variable name consistent (optimalCapacity)
        int optimalCapacity = high; 

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(canShipwithcapacity(weights, days, mid)){
                optimalCapacity = mid; // Fixed name here
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return optimalCapacity; // 4. Added missing semicolon
    }
};