class Solution {
public:
    
    vector<int> diffWaysToCompute(string expression) {
        
        return compute(0, expression.size()-1, expression);
    }
    
    vector<int> compute(int start, int end, string &exp) {
        
        bool is_full_num = true;
        vector<int> result;
        
        if(start < 0 ||  end > exp.size()-1) return result;
        
        for(int i=start; i<=end; i++) {

            if(exp[i] == '+' || exp[i] == '*' || exp[i] == '-') {
                
                is_full_num = false; // This expression contains both numbers and operator
                // Split a operator point
                vector<int> left_vals = compute(start, i-1, exp);
                vector<int> right_vals = compute(i+1, end, exp);
                
                // DO all combinations of the operation
                for(int l=0; l<left_vals.size(); l++) {
                    for(int r=0; r<right_vals.size(); r++) {
                        
                        if(exp[i] == '+') {
                            result.push_back(left_vals[l] + right_vals[r]); 
                        } else if(exp[i] == '-') {
                            result.push_back(left_vals[l] - right_vals[r]);
                        } else if(exp[i] == '*') {
                            result.push_back(left_vals[l] * right_vals[r]);
                        }
                        
                    }
                }
                
                
            }
        }
        

        if(is_full_num) {
            // This is a plain number string
            int num = 0;
            
            int pow_10 = 0;
            for(int i=end; i>=start; i--) {
                num += (exp[i] - '0') * pow(10, pow_10);
                pow_10++;
            }
            
            result.push_back(num);
            
            return result;
        }
        
        return result; // Never reached
    }
};
