/*
Given a string s, return the longest palindromic substring in s.
*/

class Solution {
public:
    int max_p_size = 1;
    string ret;

    string longestPalindrome(string s) {

        ret = string(1, s[0]);
        for(int i=0; i<(s.size()-1); i++) {
            if(s[i] == s[i+1]) {
                palin_get_from_center(i,i+1,s); // even len
                if(i>0) palin_get_from_center(i,i,s); // odd len
            } else {
                if(i>0) palin_get_from_center(i,i,s); // odd len
            }
        }
        
        return ret;
    }

    // i and j are the centers of the palin
    void palin_get_from_center(int i, int j, string &s) {

        int p_size = 1; // odd len palin test
        if(j == i+1) p_size = 2; // even len palin test

        // Expand from center
        int l=1, r=1;
        while((i-l)>=0 && (j+r)<s.size()) {
            if(s[i-l] == s[j+r]) {
                l++;r++;
                p_size+=2;
            } else {
                break;
            }
        }

        // Update max size and max string
        if(p_size > max_p_size) {
            max_p_size = p_size;
            l--;r--;
            int str_len = (j+r) - (i-l) + 1;
            ret = s.substr(i-l, str_len);
        }
    }
};
