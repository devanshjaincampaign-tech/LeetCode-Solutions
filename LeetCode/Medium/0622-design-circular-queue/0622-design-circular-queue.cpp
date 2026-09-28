class MyCircularQueue {
private:
    vector<int>cq;
    int rear=-1;
    int front=-1;
public:
    MyCircularQueue(int k) {
        cq.resize(k);
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }

        if(isEmpty()){
            front=0;
        }

        rear=(rear+1)%cq.size();
        cq[rear]=value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }

        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%cq.size();
        }

        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return cq[front];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return cq[rear];
    }
    
    bool isEmpty() {
        return front==-1;
    }
    
    bool isFull() {
        return (rear + 1) % cq.size() == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */