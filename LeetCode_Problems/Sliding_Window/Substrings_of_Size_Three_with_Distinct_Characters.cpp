/*

A string is good if there are no repeated characters.

Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.

Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

A substring is a contiguous sequence of characters in a string.

*/

class Solution {
public:
    int countGoodSubstrings(string s) {
        
        int end = 0;
        int good_strings = 0;
      
        for(end = 0; end < s.size(); end++) {
            
            if(end <= 2) {

                if(end == 2) {
                    if(s[end] != s[end-1] && s[end-1] != s[end-2] && s[end-2] != s[end]) good_strings++;
                }

            } else {

                if(s[end] != s[end-1] && s[end-1] != s[end-2] && s[end-2] != s[end]) good_strings++;

            }
            
        }
        
        return good_strings;
    }
};
