/*
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

*/

class Solution {
public:

    class ele {
    public:
        long long val;
        char op;

        ele(long long v, char o) {
            val = v;
            op = o;
        }
    };

    int calculate(string s) {

        stack<ele> stk;

        for(int i=0; i<s.size(); i++) {

            bool is_num = false;
            long long op2 = 0;
            if(s[i] == ' ') {
                continue;
            } else if( (s[i]-'0') <= 9 && (s[i]-'0') >= 0) {

                while( (i<=s.size()-1) && ((s[i]-'0') <= 9 && (s[i]-'0') >= 0) ) {
                    op2 *= 10;
                    op2 += s[i] - '0';
                    i++;
                }
                i--;

                is_num = true;
            } else {
                stk.push( ele(0, s[i]) );
                is_num = false;
            }

            if(is_num) {

                if(!stk.empty() && (stk.top().op == '*' || stk.top().op == '/') ) {

                    char o = stk.top().op;
                    stk.pop();
                    long long op1 = stk.top().val;
                    stk.pop();
                    long long ans = 0;

                    if(o == '/') {
                        ans = op1 / op2;
                    } else { // *
                        ans = op1 * op2;
                    }

                    stk.push(ele(ans, 'N'));
                    
                } else {
                    stk.push(ele(op2, 'N'));
                }
            }

        }

        char operand = 'N';
        long long ans = 0;
        vector<ele> expr;
        while(!stk.empty()) { 
            expr.push_back(stk.top());
            stk.pop();
        }
        reverse(expr.begin(), expr.end());

        for(int i=0; i<expr.size(); i++) {

            if(expr[i].op != 'N') {
                operand = expr[i].op;
            } else {
                long long op2 = expr[i].val;
                if(operand == '-') {
                    ans -= op2;
                } else { // +
                    ans += op2;
                }
                operand = 'N';
            }
        }

        return ans;
        
    }
};
