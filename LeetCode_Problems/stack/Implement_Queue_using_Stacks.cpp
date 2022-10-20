class MyQueue {
public:
    
    stack<int> s1;
    stack<int> s2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        
        int val;
        while(!s1.empty()) {
            val = s1.top();
            s1.pop();
            if(s1.empty()) break;
            s2.push(val);
        }
        
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        
        return val;
        
    }
    
    int peek() {
        int val;
        while(!s1.empty()) {
            val = s1.top();
            s1.pop();
            s2.push(val);
        }
        
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        
        return val;
    }
    
    bool empty() {
        return s1.empty();
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
