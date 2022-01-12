class Solution {
public:
    int findTheLongestSubstring(string s) {
        
        int start = 0;
        int contains_odd = 0;
        int end = 0;
        int max_len = 0;
        
        for(start = 0; start < s.size(); start++) {
            if(max_len >= s.size() - start) break;
            contains_odd = 0;
            for(end = start; end < s.size(); end++) {
                if(isVowel(s[end])) contains_odd ^= s[end];
                
                if(!contains_odd) max_len = max(max_len, end - start + 1);
            }
        }
        
        return max_len;
    }
    
    bool isVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
};
