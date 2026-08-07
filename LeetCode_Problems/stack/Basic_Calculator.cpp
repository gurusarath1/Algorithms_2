/*
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Example 1:

Input: s = "1 + 1"
Output: 2
Example 2:

Input: s = " 2-1 + 2 "
Output: 3
Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
 

Constraints:

1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.

*/


class Solution {
public:

    // element: operand or number
    class ele {
    public:
        int val;
        string op;
        ele(int v, string o) {
            val = v;
            op = o;
        }
    };

    int calculate(string s) {
        return calc(s,0).first;
    }

    pair<int,int> calc(string &s, int idx) {

        queue<ele> q;
        int i=idx;

        for(; i<s.size(); i++) {
            
            if(s[i] == '(') {
                // Nest stack
                pair<int,int> result = calc(s, i+1);
                int val = result.first;
                q.push(ele(val, ""));
                i = result.second;

            } else if (s[i] == ')') {
                // End
                break;

            } else if( (s[i] == '-' && !q.empty()) || s[i] == '+') { //if + or not first -
                q.push( ele(0, string(1,s[i])) );

            } else if(s[i] == ' ') {
                // ignore
                continue;

            } else {
                double val = 0;
                bool neg = false;

                // -val or -(val) or -   val or -  (val) pattern
                if(s[i] == '-') {
                    neg = true;
                    i++;
                }

                // ignore blank spaces
                while(s[i] == ' ') {
                    i++;
                }

                // -() pattern
                if(s[i] == '(')
                {
                    pair<int,int> result = calc(s, i+1);
                    val = result.first;
                    i = result.second;
                } else {

                    while(s[i] >= '0' && s[i] <= '9') {
                        int digit = s[i] - '0';
                        val = (val*10) + digit;
                        i++;
                    }
                    i--;
                }

                if(neg) {
                    val = -val;
                }

                q.push(ele(val, ""));
            }
        }

        /* Calculate the result */
        string op = "";
        int ans = 0;
        while(!q.empty()) {
            ele e = q.front();

            if(e.op == "") {
                if(op == "" || op == "+")
                {
                    ans += e.val;
                } else if(op == "-") {
                    ans -= e.val;
                }
            } else {
                op = e.op;
            }

            q.pop();
        }

        return pair<int,int>{ans,i};
    }
};
