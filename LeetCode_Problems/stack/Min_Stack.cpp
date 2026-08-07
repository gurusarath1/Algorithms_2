/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int value) pushes the element value onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
*/

class MinStack {
public:

    stack<pair<int,int>> min_stack;

    MinStack() {
        
    }
    
    void push(int value) {
        if(min_stack.empty()) {
            min_stack.push(pair<int,int>{value, value});
        } else {
            int min_val = getMin();
            if(min_val > value) {
                min_stack.push(pair<int,int>{value, value});
            } else {
                min_stack.push(pair<int,int>{value, min_val});
            }
        }
    }
    
    void pop() {
        min_stack.pop();
    }
    
    int top() {
        return min_stack.top().first;
    }
    
    int getMin() {
        return min_stack.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
