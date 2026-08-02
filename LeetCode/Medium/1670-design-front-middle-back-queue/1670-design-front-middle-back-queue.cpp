class FrontMiddleBackQueue {
private:
    deque<int> left;
    deque<int> right;

    void rebalance() {
        if (left.size() > right.size()) {
            right.push_front(left.back());
            left.pop_back();
        } else if (right.size() > left.size() + 1) {
            left.push_back(right.front());
            right.pop_front();
        }
    }

public:
    FrontMiddleBackQueue() {}
    
    void pushFront(int val) {
        left.push_front(val);
        rebalance();
    }
    
    void pushMiddle(int val) {
        if (left.size() == right.size()) {
            right.push_front(val);
        } else {
            left.push_back(val);
        }
        rebalance();
    }
    
    void pushBack(int val) {
        right.push_back(val);
        rebalance();
    }
    
    int popFront() {
        if (right.empty()) return -1;
        
        int val;
        if (left.empty()) {
            val = right.front();
            right.pop_front();
        } else {
            val = left.front();
            left.pop_front();
        }
        rebalance();
        return val;
    }
    
    int popMiddle() {
        if (right.empty()) return -1;
        
        int val;
        if (left.size() == right.size()) {
            val = left.back();
            left.pop_back();
        } else {
            val = right.front();
            right.pop_front();
        }
        rebalance();
        return val;
    }
    
    int popBack() {
        if (right.empty()) return -1;
        
        int val = right.back();
        right.pop_back();
        rebalance();
        return val;
    }
};