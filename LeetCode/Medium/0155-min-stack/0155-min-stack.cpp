class MinStack {
private:
    vector<int> vec;
    vector<int> minVec; // Keeps track of current minimums

public:
    MinStack() {}
    
    void push(int value) {
        vec.push_back(value);
        
        // Push the new minimum into minVec
        if (minVec.empty() || value <= minVec.back()) {
            minVec.push_back(value);
        } else {
            minVec.push_back(minVec.back());
        }
    }
    
    void pop() {
        if (!vec.empty()) {
            vec.pop_back();
            minVec.pop_back();
        }
    }
    
    int top() {
        return vec.back();
    }
    
    int getMin() {
        return minVec.back(); // O(1) time complexity!
    }
};