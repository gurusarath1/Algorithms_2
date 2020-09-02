/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:
Input: "A man, a plan, a canal: Panama"
Output: true

Example 2:
Input: "race a car"
Output: false
*/


class Solution {
public:
    bool isPalindrome(string s) {
        
        int i = 0;
        int j = s.size() - 1;
        
        while(i < j) {
            if(is_alphanum(s[i]) && is_alphanum(s[j])) {
                if(!compare_chars_ignore_case(s[i],s[j]))
                {
                    return false;
                }
            } else {
                if(!is_alphanum(s[i])) {
                    i++;
                    continue;
                } else if(!is_alphanum(s[j])) {
                    j--;
                    continue;
                }
            }
            
            i++;
            j--;
        }
        
        return true;
    }
    
    bool is_alphanum(char x) {
        if( (x >= 65 && x <= 90) || (x >= 97 && x <= 122) || (x >= 48 && x <= 57) ) {
            return true;
        } else {
            return false;
        }
    }
    
    bool is_alpha(char x) {
        if( (x >= 65 && x <= 90) || (x >= 97 && x <= 122)) {
            return true;
        } else {
            return false;
        }   
    }
    
    bool compare_chars_ignore_case(char a, char b) {
        if(a < b) {
            return compare_chars_ignore_case(b,a);
        }
        
        if(a == b) {
            return true;
        }
        
        if(is_alpha(a) && is_alpha(b)) {
            if(a-32 == b) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};
