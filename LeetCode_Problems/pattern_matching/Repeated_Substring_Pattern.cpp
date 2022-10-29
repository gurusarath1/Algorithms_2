class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int lps[s.size()];
        
        int i = 0;
        int j = 1; // only moves forward
        lps[0] = 0;
        while(j < s.size()) {
            
            if(s[i] == s[j]) {
                lps[j] = i + 1;
                i++;
                j++;
            } else {
                
                if(i == 0) {
                    lps[j] = 0;
                    j++;
                } else {
                    i = lps[i - 1];
                }
                
            }
        }
                
        int len_suffix = lps[s.size() - 1];
        int len_substring = s.size() - len_suffix;
        
        if(len_suffix == 0) return false;
        
        if(s.size() % len_substring == 0) return true;
        
        return false;
    }
};
