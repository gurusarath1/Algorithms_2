class Solution {
public:

    
    int calPoints(vector<string>& ops) {
        stack<int> stk;
        int num1;
        int num2;
        
        for(string s : ops) {
            if(s[0] == '-' || s[0] >= '0' && s[0] <= '9') {
                stk.push(stoi(s));
            } else {
                switch(s[0]) {
                    case 'C':

                        stk.pop();
                        break;

                    case 'D':

                        num1 = stk.top();
                        
                        stk.push(num1*2);
                        break;

                    case '+':

                        num1 = stk.top();
                        stk.pop();
                        
                        num2 = stk.top();
                        stk.pop();
                        
                        stk.push(num2);
                        stk.push(num1);
                        
                        stk.push(num1 + num2);

                        break;
                }
            }
        }
        
        int result = 0;
        while(!stk.empty()) {
            num1 = stk.top();
            stk.pop();
            
            result += num1;
        }
        
        return result;
    }
};
