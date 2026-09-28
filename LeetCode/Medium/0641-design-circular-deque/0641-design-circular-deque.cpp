#include <vector>

class MyCircularDeque {
private:
    std::vector<int> dq;
    int front;
    int rear;
    int capacity;
    int count;

public:
    MyCircularDeque(int k) {
        capacity = k;
        dq.resize(k);
        front = 0;
        rear = 0;
        count = 0;
    }
    
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }
        dq[front] = value;
        count++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        dq[rear] = value;
        count++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        count--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        rear = (rear - 1 + capacity) % capacity;
        count--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return dq[front];
    }
    
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return dq[rear];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
};