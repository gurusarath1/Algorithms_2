class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int i=0;
        int j=0;
        
        while(i < haystack.size()) {
            
            int k = i;
            while(k < haystack.size() && j < needle.size() && haystack[k] == needle[j]) {
                k++;
                j++;
            }
            
            if(j == needle.size()) return i;
            else j = 0;
            
            i++;
        }
        
        return -1;
        
    }
};
