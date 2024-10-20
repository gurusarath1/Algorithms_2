class Solution {
public:
    bool parseBoolExpr(string expression) {

        stack<char> op_stk;
        stack<bool> vals_stk;
        stack<int> oprnd_counts;

        int oprnd_start = false;
        for(int i=0; i<expression.size(); i++) {

            if(expression[i] == '!' | expression[i] == '|' | expression[i] == '&') {
                if(expression[i] == '!') {
                    op_stk.push('!');
                } else if(expression[i] == '|') {
                    op_stk.push('|');
                } else if(expression[i] == '&') {
                    op_stk.push('&');
                }
                i++;
                if(oprnd_start) {
                    oprnd_counts.push(1);
                } else if(!oprnd_counts.empty()) {
                    int num_ops = oprnd_counts.top();
                    oprnd_counts.pop();
                    oprnd_counts.push(num_ops + 1);
                }

                oprnd_start = true;
                continue;
            }

            if(expression[i] == ',') {
                continue;
            }

            if(expression[i] == 't' | expression[i] == 'f') {
                if(expression[i] == 't') {
                    vals_stk.push(true);
                } else if(expression[i] == 'f') {
                    vals_stk.push(false);
                }

                if(oprnd_start) {
                    oprnd_counts.push(1);
                } else {
                    int oprnd_count = oprnd_counts.top();
                    oprnd_counts.pop();
                    oprnd_counts.push(oprnd_count+1);
                }

                oprnd_start = false;

                continue;
            }

            if(expression[i] == ')') {
                bool sub_expr;

                sub_expr = vals_stk.top();
                vals_stk.pop();
                int num_oprnds = oprnd_counts.top();
                oprnd_counts.pop();
                char op = op_stk.top();
                op_stk.pop();

                if(op == '!') {

                    sub_expr = !sub_expr;

                } else if(op == '|') {

                    for(int i=1; i<num_oprnds; i++) {
                        sub_expr |= vals_stk.top();;
                        vals_stk.pop();
                    }

                } else if(op == '&') {

                    for(int i=1; i<num_oprnds; i++) {
                        sub_expr &= vals_stk.top();;
                        vals_stk.pop();
                    }
                }

                vals_stk.push(sub_expr);
            }

        }

        assert(vals_stk.size() == 1);

        return vals_stk.top();
    }
};
