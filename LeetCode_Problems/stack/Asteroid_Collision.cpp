class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> stk;
        
        for(int ast : asteroids) {
            
            if(!stk.empty()) {
                
                if(stk.top() > 0 && ast < 0) {
                    
                    while(!stk.empty() && stk.top() > 0 && abs(ast) > stk.top()) {
                        stk.pop();
                    }
                    
                    if(stk.empty()) {
                        stk.push(ast);
                    } else {
                        if(stk.top() == abs(ast)) {
                            stk.pop();
                        } else if (stk.top() > abs(ast)) {
                            ;
                        } else {
                            stk.push(ast);
                        }
                    }
                    
                } else {
                    stk.push(ast);
                }
                
                
            } else {
                stk.push(ast);
            }
            
        }
        
        vector<int> result;
        while(!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
        
    }
};
