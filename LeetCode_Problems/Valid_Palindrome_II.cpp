class Solution {
public:
    
    bool is_palindrome(string &s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        
        return true;
    }
    
    bool validPalindrome(string s) {
        int i=0;
        int j=s.size() - 1;
        
        while(i < j) {
            if(s[i] != s[j]) {
                return is_palindrome(s,i+1,j) || is_palindrome(s,i,j-1);
            }
            
            i++;
            j--;
        }
        
        return true;
    }
};
