class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        
        if(s.size() == 0) return true;
        
        for(j=0; j<t.size(); j++) {
            
            if(t[j] == s[i]) {
                i++;
            }
            
            if(i == s.size()) return true;
        }
        
        return false;
        
    }
};
