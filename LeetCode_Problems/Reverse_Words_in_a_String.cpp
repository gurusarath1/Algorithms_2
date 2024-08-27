class Solution {
public:
    string reverseWords(string s) {

        string word = "";
        string rev_string = "";
        stack<string> stk;

        int i=0;
        while(i < s.size() && s[i] == ' ') {
            i++;
        }

        while(i < s.size()) {
            while(i < s.size() && s[i] != ' ') {
                word += s[i];
                i++;
            }

            if(word.size()) {
                stk.push(word);
                word = "";
            }
            i++;

        }

        while(!stk.empty()) {
            rev_string += stk.top();
            if(stk.size() > 1) rev_string += " ";
            stk.pop();
        }
        
        return rev_string;
        
    }
};
