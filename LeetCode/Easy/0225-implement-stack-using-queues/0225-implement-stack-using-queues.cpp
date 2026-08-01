class MyStack {
private:
    queue<int>que;
public:
    MyStack() {
        //
    }
    
    void push(int x) {
        
        int n=que.size();
    que.push(x);
        for(int i=0;i<n;i++){
            que.push(que.front());
            que.pop();
        }
    }
    
    int pop() {
        int temp=que.front();
        que.pop();
        return temp;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */