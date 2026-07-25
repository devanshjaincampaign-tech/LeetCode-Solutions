class Solution {
public:
    int maxProduct(int n) {
        vector<int>numbers;
        while(n!=0){
            numbers.push_back(n%10);
            n/=10;
        }   

        sort(numbers.begin(),numbers.end());

        int size=numbers.size()-1;
        return numbers[size-1]*numbers[size];
    }
};