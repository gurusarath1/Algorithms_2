class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        for(char c : s) {
            bool not_found = true;
            for(; i<t.size(); i++) {
                if(t[i] == c) {
                    not_found = false;
                    i++;
                    break;
                }
            }
            
            if(not_found) return false;
        }
        
        return true;
    }
};
