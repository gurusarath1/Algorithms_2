/*
Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(needle.size() == 0) {
            return 0;
        }
        
        int count = 0;
        for(int i=0; i<haystack.size(); i++) {
            
            if(haystack[i] == needle[0]) {
                
                int k = i+1;
                int j = 1;
                count = 1;
                while(k < haystack.size() && j < needle.size() &&haystack[k] == needle[j]) {
                    count++;
                    k++;
                    j++;
                }
                
                if(count == needle.size()) {
                    return i;
                } else {
                    count = 0;
                }
            }
            
            if(haystack.size() - needle.size() <= i)
            {
                return -1;
            }
        }
        
        return -1;
    }
};
