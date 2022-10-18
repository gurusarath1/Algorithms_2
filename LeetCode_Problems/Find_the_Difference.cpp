class Solution {
public:
    char findTheDifference(string s, string t) {
        
        multiset<char> chars_in_s;
        
        for(int i=0; i<s.size(); i++) {
            chars_in_s.insert(s[i]);
        }
        
        for(int i=0; i<t.size(); i++) {
            if(chars_in_s.find(t[i]) == chars_in_s.end()) {
                return t[i];
            }
            
            // To erase only one of the occurence of the char
            auto itr = chars_in_s.find(t[i]);
            if(itr!=chars_in_s.end()){
                chars_in_s.erase(itr);
            }
        }
        
        return '0'; // Never reached
        
    }
};
