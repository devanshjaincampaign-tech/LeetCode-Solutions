class MyQueue {
private: 
    stack<int>inputstack;
    stack<int>outputstack;

    void shiftstack(){
        if(outputstack.empty()){
            while(!inputstack.empty()){
                outputstack.push(inputstack.top());
                inputstack.pop();
            }
        }
    }
public:
    MyQueue() {
        //
    }
    
    void push(int x) {
        inputstack.push(x);
    }
    
    int pop() {
        shiftstack();
        int temp=outputstack.top();
        outputstack.pop();
        return temp;
    }
    
    int peek() {
        shiftstack();
        int temp=outputstack.top();
        return temp;
    }
    
    bool empty() {
        return (inputstack.empty() && outputstack.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */