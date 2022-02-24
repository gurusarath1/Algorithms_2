class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> stk;
        
        for(int i=0; i<s.size(); i++) {
            
            char c = s[i];
            
            switch(c) {
                case '(':
                    stk.push({c,i});
                    break;
                case ')':
                    if(!stk.empty() && stk.top().first == '(') {
                        stk.pop();
                    } else {
                        stk.push({c,i});
                    }
                    break;
                default:
                    break;
            }
            
        }
                                
        while(!stk.empty()) {
            int index = stk.top().second;
            s.erase(s.begin() + index);
            stk.pop();
        }
        
        return s;
    }
};
