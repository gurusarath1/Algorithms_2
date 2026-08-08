/*
Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if:

Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
In other words, we treat '(' as an opening parenthesis and '))' as a closing parenthesis.

For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced.
You can insert the characters '(' and ')' at any position of the string to balance it if needed.

Return the minimum number of insertions needed to make s balanced.

*/

class Solution {
public:
    int minInsertions(string s) {

        stack<char> stk;
        int ins = 0;

        // Main idea:
        /*
        - Push only (
        - Match ()) and remove form stack
        - Count when pairs are not found
        */

        for(int i=0; i<s.size(); i++) {
            if(s[i] == ')' && i+1<s.size() && s[i+1] == ')') {

                // Pattern: ))
                if(!stk.empty() && stk.top() == '(') {
                    // Match!!
                    // Pattern: ())
                    stk.pop();
                } else {
                    // Pattern: ))
                    ins += 1; // one (
                }

                i++; // Skip the next )

            } else if(s[i] == '(') { // Pattern: (
                stk.push(s[i]);

            } else if(s[i] == ')') { // Patter: )( or )<end>

                if(!stk.empty() && stk.top() == '(') { // Pattern ()( or ()<end>
                    stk.pop();
                    ins += 1; // one )
                } else {
                    ins += 2; // one ( and )
                }
            }
        }

        // Only ( lest in stack
        if(!stk.empty()) {
            ins += stk.size() * 2; // we need two ) for each (
        }

        return ins;
    }
};
