class MyCircularQueue {
private:
    vector<int> circularqueue;
    int head;
    int tail;
    int count;
    int capacity;

public:
    MyCircularQueue(int k) {
        circularqueue.resize(k);
        capacity = k;
        head = 0;
        tail = 0;
        count = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        
        circularqueue[tail] = value;
        tail = (tail + 1) % capacity; // Wrap around to index 0 if tail hits end
        count++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        
        head = (head + 1) % capacity; // Wrap around to index 0 if head hits end
        count--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return circularqueue[head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        // Since tail points to the next available empty spot, 
        // the last inserted element is at (tail - 1 + capacity) % capacity
        return circularqueue[(tail - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
};