/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([)]"
Output: false

Example 5:
Input: s = "{[]}"
Output: true
*/


class Solution {
public:
    bool isValid(string s) {
        
        stack<char> stk;
        char x;
        
        for(int i=0; i<s.size(); i++) {
            
            x = s[i];
            
            if(x == ']' || x == '}' || x == ')') {
                if(stk.empty()) {
                    return false;
                }
            }
            
            switch(x) {
                case '[':
                case '(':
                case '{':
                    stk.push(x);
                    break;
                case ')':
                    if( stk.top() != '(') {return false;}
                    stk.pop();
                    break;
                case '}':
                    if( stk.top() != '{') {return false;}
                    stk.pop();
                    break;
                case ']':
                    if( stk.top() != '[') {return false;}
                    stk.pop();
                    break;
            }
        }

        if(!stk.empty()) {
            return false;
        }

        return true;
    }
};
