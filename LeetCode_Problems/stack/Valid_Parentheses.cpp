class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        map<char, char> m;
        m[']'] = '[';
        m['}'] = '{';
        m[')'] = '(';

        for(char c : s) {
            if(c == '}' || c == ']' || c == ')') {
                if(stk.empty()) {
                    return false;
                } else {
                    char top_c = stk.top();
                    if(top_c == m[c]) {
                        stk.pop();
                    } else {
                        return false;
                    }
                }
            } else {
                stk.push(c);
            }
        }

        if(stk.empty()) return true;
        
        return false;
    }
};
