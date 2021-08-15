class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int prev_len = 0;
        int current_len = 0;
        
        for(int i=0; i<s.size(); i++) {
           
            if(s[i] == ' ') {
                prev_len = current_len;
                current_len = 0;
                
                while(i<s.size() && s[i] == ' ') i++;
                i--;
            } else {
                current_len++;
            }
            
        }
        
        if(current_len == 0 && prev_len != 0) return prev_len;
        
        return current_len;
        
    }
};
