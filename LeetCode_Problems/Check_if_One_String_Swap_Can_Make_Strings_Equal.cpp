class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        int mismatch_count = 0;
        char expected_char_in_s2, expected_char_in_s1;
        
        for(int i=0; i<s1.size(); i++) {
            if(s1[i] != s2[i]) {
                
                if(mismatch_count == 0) {
                    mismatch_count++;
                    expected_char_in_s2 = s1[i];
                    expected_char_in_s1 = s2[i];
                } else if(mismatch_count == 1) {
                    mismatch_count++;
                    
                    if(expected_char_in_s1 != s1[i]) return false;
                    if(expected_char_in_s2 != s2[i]) return false;
                    
                } else {
                    return false;
                }
                
            }
        }
        
        if(mismatch_count != 2 && mismatch_count != 0) return false;
        
        return true;
    }
};
