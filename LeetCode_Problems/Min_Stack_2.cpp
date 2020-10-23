/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {
public:
    /** initialize your data structure here. */
    
    stack<int> min_stack;
    int min;
    
    MinStack() {
        
        min = INT_MAX;
        
    }
    
    void push(int x) {
        
        if(x <= min) {
            min_stack.push(min);
            min = x;
        }
        
        min_stack.push(x);
        
    }
    
    void pop() {
        
        if(min_stack.top() == min) {
            min_stack.pop();
            min = min_stack.top();
        }
        
        min_stack.pop();
    }
    
    int top() {
        
        return min_stack.top();
        
    }
    
    int getMin() {
        
        return min;
        
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
