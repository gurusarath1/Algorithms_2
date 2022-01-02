/*
Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

*/

class Solution {
public:
    string removeOuterParentheses(string s) {
        
        stack<char> c_s;
        stack<int> i_s;
        set<int> deletion_indices;
        
        int index = 0;
        for(char c : s) {
            if(c == '(') {
                c_s.push(c);
                i_s.push(index);
            } else if(c == ')') {
                if(c_s.size() == 1) {
                    deletion_indices.insert(index);
                    deletion_indices.insert(i_s.top());
                }
                c_s.pop();
                i_s.pop();
            }
            index++;
        }
        
        string result = "";
        index = 0;
        for(char c : s) {
            if(deletion_indices.find(index) != deletion_indices.end()) {
                ;
            } else {
                result += c;
            }
            index++;
        }
        
        return result;
    }
};
