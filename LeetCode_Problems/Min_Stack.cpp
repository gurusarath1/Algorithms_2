class MinStack {
public:
    /** initialize your data structure here. */
    
    stack<int> regular_stack;
    stack<int> min_stack;
    
    MinStack() {
        
    }
    
    void push(int x) {
        
        if(min_stack.empty() || x <= min_stack.top()) {
            min_stack.push(x);
        }
        
        regular_stack.push(x);
        
    }
    
    void pop() {
        
        if(regular_stack.top() == min_stack.top()) {
            min_stack.pop();
        }
        
        regular_stack.pop();
    }
    
    int top() {
        
        return regular_stack.top();
        
    }
    
    int getMin() {
        
        return min_stack.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
