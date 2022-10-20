class MyQueue {
public:
    
    stack<int> stk;
    int peek_val;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        stk.push(x);
    }
    
    int pop() {
        
        int val;

        if(stk.size() > 0) {
            val = stk.top();
            stk.pop();
        } else {
            // Empty stack
            return 0;
        }
        
        if(stk.size() == 0) {
            peek_val = val;
            return peek_val;
        } else {
            this->pop();
        }
        
        stk.push(val);
        
        return peek_val;
        
    }
    
    int peek() {
        int val;
        
        if(stk.size() > 0) {
            val = stk.top();
            stk.pop();
        } else {
            // Empty stack
            return 0;
        }

        
        if(stk.size() == 0) {
            peek_val = val;
        } else {
            this->peek();
        }
        
        stk.push(val);
        
        return peek_val;
    }
    
    bool empty() {
        return stk.empty();
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
