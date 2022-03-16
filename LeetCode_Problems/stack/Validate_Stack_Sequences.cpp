class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> stk;
        
        int i = 0;
        int j = 0;
        
        while(1) {
            
            if(stk.empty()) {
                stk.push(pushed[i]);
                i++;
            }
            else if(!stk.empty() && stk.top() != popped[j]) {
                
                if(i >= pushed.size()) return false;
                
                stk.push(pushed[i]);
                i++;            
            } else {
                stk.pop();
                j++;
                if(j >= popped.size()) return true;
            }
            
        }
        
        
        return false; //dummy
    }
};
