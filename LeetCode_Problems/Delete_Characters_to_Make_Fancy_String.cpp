class Solution {
public:
    string makeFancyString(string s) {

        string ret = "";
        char prev = ' ';
        int count = 1;
        for(char c : s) {
            if(c == prev) {
                count++;
                if(count >= 3) continue;
            } else {
                count = 1;
            }

            ret += c;

            prev = c;
        }

        return ret;
        
    }
};
