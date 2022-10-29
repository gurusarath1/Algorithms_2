class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<long long> stk;
        
        for(string tok : tokens) {
            if( (tok[0] == '-' && tok.size() >= 2) || (tok[0] >= '0' && tok[0] <= '9') ) {
                stk.push(get_num(tok));
            } else {
                
                long long num2 = stk.top(); stk.pop();
                long long num1 = stk.top(); stk.pop();
                
                switch(tok[0]) {
                    case '+':
                        stk.push(num1 + num2);
                        break;
                    case '-':
                        stk.push(num1 - num2);
                        break;
                    case '*':
                        stk.push(num1 * num2);
                        break;
                    case '/':
                        stk.push(num1 / num2);
                        break;
                }
                
            }
        }
        
        return stk.top();
        
    }
    
    long long get_num(string s) {
        
        long long num = 0;
        long long pow = 1;
        
        for(int i = s.size() - 1; i>=0; i--) {
            
            if(s[i] == '-') {
                num = -num;
                break;
            }
            
            int digit = s[i] - '0';
            num = num + (digit * pow);
            pow *= 10;
        }
        
        return num;
    }
    
};
