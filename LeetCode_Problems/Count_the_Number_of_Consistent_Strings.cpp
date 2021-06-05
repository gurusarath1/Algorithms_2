class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        set<char> allowed_chars;
        int allowed_strings = 0;
        bool allowed_flag;
        
        for(char c : allowed) {
            allowed_chars.insert(c);
        }
        
        for(string s : words) {
            
            allowed_flag = true;
            for(char c : s) {
                if(allowed_chars.find(c) == allowed_chars.end()) {
                    allowed_flag = false;
                    break;
                }
            }
            
            if(allowed_flag) allowed_strings++;
        }
        
        return allowed_strings;
    }
};
