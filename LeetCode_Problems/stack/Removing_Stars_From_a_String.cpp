class Solution {
public:
    string removeStars(string s) {

        stack<char> stk;
        string ret = "";

        for(char c : s) {

            if(c == '*') {
                if(!stk.empty()) {
                    stk.pop();
                }
            } else {
                stk.push(c);
            }
        }

        while(!stk.empty()) {
            ret += stk.top();
            stk.pop();
        }

        reverse(ret.begin(), ret.end());

        return ret;
        
    }
};
