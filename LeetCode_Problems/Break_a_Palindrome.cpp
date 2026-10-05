class Solution {
public:
    string breakPalindrome(string palindrome) {
        string res = "";
        unsigned int sz = palindrome.size();
        int center = -1;

        if(sz & 1) {
            center = sz / 2;
        }

        bool no_flip = true;
        for(int i=0; i<palindrome.size();  i++) {
            char c = palindrome[i];

            if(i != center && no_flip && c != 'a') {
                c = 'a';
                no_flip = false;
            }

            if(i == sz-1 && no_flip && sz != 1) {
                c = 'b';
                no_flip = false;
            }

            res += c;
        }

        if(no_flip) {
            return "";
        }
        
        return res;
    }
};
