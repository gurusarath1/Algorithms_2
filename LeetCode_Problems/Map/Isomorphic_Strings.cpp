class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> char_mapping_1;
        map<char,char> char_mapping_2;
        
        for(int i=0; i<s.size(); i++) {
            // Check mapping from string 1 -> 2
            if(char_mapping_1.find(s[i]) != char_mapping_1.end() && char_mapping_1[s[i]] != t[i]) {
                return false;
            } else {
                char_mapping_1[s[i]] = t[i];
            }
            // Check mapping from string 2 -> 1
            if(char_mapping_2.find(t[i]) != char_mapping_2.end() && char_mapping_2[t[i]] != s[i]) {
                return false;
            } else {
                char_mapping_2[t[i]] = s[i];
            }
        }
        
        return true;
    }
};
