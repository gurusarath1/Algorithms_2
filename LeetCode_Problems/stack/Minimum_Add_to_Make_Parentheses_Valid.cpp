class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<char> stk;
        
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                stk.push('(');
            } else if(s[i] == ')') {
                if(!stk.empty() && stk.top() == '(') {
                    stk.pop();
                } else {
                    stk.push(')');
                }
            }
        }
        
        return stk.size();
        
    }
};
