class Solution {
public:
    
    stack<string> digits_stack;
    
    string addBinary(string a, string b) {
        
        int index_a = a.size() - 1;
        int index_b = b.size() - 1;
        
        string result = "";
        
        add_support(a, b, index_a, index_b, 0);
        
        while(!digits_stack.empty()) {
            result.append(digits_stack.top());
            digits_stack.pop();
        }
        
        return result;
        
    }
    
    void add_support(string &a, string &b, int index_a, int index_b, int carry) {
        
        int index = (index_a > index_b)? index_a : index_b;
        
        if(index == -1) {
            if(carry == 1) digits_stack.push("1");
            return;
        }
        
        char digit_a, digit_b; 
        
        if(index_a >= 0) digit_a = a[index_a]; else digit_a = '0';
        if(index_b >= 0) digit_b = b[index_b]; else digit_b = '0';
        
        if(digit_a + digit_b + carry - '0' - '0' == 3) {
            
            digits_stack.push("1");
            add_support(a,b,index_a-1,index_b-1, 1);
            
        } else if (digit_a + digit_b + carry - '0' - '0' == 2) {
            
            digits_stack.push("0");
            add_support(a,b,index_a-1,index_b-1, 1);
            
        } else if (digit_a + digit_b + carry - '0' - '0' == 1) {
            
            digits_stack.push("1");
            add_support(a,b,index_a-1,index_b-1, 0);
            
        } else if (digit_a + digit_b + carry - '0' - '0' == 0) {
            
            digits_stack.push("0");
            add_support(a,b,index_a-1,index_b-1, 0);
            
        }
        
        return;
        
    }
};
