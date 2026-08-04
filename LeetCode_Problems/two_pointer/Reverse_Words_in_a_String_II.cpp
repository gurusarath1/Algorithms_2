/*
Given a character array s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by a single space.

Your code must solve the problem in-place, i.e. without allocating extra space.
*/

class Solution {
public:
    void reverseWords(vector<char>& s) {

        // reverse the full sentence
        reverse_inplace(0, s.size()-1, s);

        // reverse individual words
        int l = 0;
        for(int r=1; r<s.size(); r++) {

            char ch = s[r];

            if ((ch >= 'A' && ch <= 'Z') ||
                (ch >= 'a' && ch <= 'z') ||
                (ch >= '0' && ch <= '9'))
            {
                ;
            } else { // end of word detected
                reverse_inplace(l, r-1, s);
                l = r+1;
                r = r+1; // inc in r++ next
            }

            if(r == s.size() - 1) {
                reverse_inplace(l, r, s);
            }
        }
        
    }

    void reverse_inplace(int l, int r, vector<char>&s) {
        while(l < r) {
            char c = s[l];
            s[l] = s[r];
            s[r] = c;

            l++;
            r--;
        }
    }
};
