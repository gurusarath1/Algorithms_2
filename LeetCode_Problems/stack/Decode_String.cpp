class Solution {
public:
    string decodeString(string s) {
        
        stack<char> stk;
        
        //cout << s.size();
        
        for(int i=0; i<s.size(); i++) {
            
            if(s[i] != ']') {
                stk.push(s[i]);
            } else {
                
                string build_str = "";
                while(!stk.empty() && stk.top() != '[') {
                    build_str += stk.top();
                    stk.pop();
                }
                
                stk.pop(); // pop the opening [
                
                int build_int = 0;
                int place = 1;
                while(!stk.empty() && stk.top() >= '0' && stk.top() <= '9') {
                    build_int += (stk.top() - '0')*place;
                    place *= 10;
                    stk.pop();
                }
                
                for(int j=0; j<build_int; j++) {
                    for(int k=build_str.size(); k>=0; k--) stk.push( build_str[k] ); // push in reverse
                }
                
            }
            
            
        }
        
        string result = "";
        while(!stk.empty()) {
            
            // This if statement was needed to resolve some technical issues
            // null chars were in the stack
            // we get rid of this by checking we are appending only alphabets
            if(!(stk.top() >= 'a' && stk.top() <='z')) {
                stk.pop();
                continue;
            }
            
            result += stk.top();
            stk.pop();
        }
        
        reverse(result.begin(), result.end());

        return result;
        
    }
};
