/*

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

*/

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> a;
        for (char c : s)
        {
            switch(c)
            {
                case '(':
                    a.push('(');
                    break;

                case ')':
                    if(a.empty()) return false;
                    if(a.top() != '(') return false;
                    a.pop();
                    break;

                case '[':
                    a.push('[');
                    break;

                case ']':
                    if(a.empty()) return false;
                    if(a.top() != '[') return false;
                    a.pop();
                    break;

                case '{':
                    a.push('{');
                    break;

                case '}':
                    if(a.empty()) return false;
                    if(a.top() != '{') return false;
                    a.pop();
                    break;
            }
        }
        
        if(a.empty())
        {
            return true;
        } else {
            return false;
        }
        
    }
};
