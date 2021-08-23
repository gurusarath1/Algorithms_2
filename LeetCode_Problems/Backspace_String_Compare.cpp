class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        string a = "";
        string b = "";
        
        
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '#') {
                if(a.length() > 0) {
                    a = a.substr(0,a.size() - 1);
                }
                
            } else {
                a = a + s[i];
            }
        }

        
        for(int i=0; i<t.size(); i++) {
            if(t[i] == '#') {
                if(b.length() > 0) {
                    b = b.substr(0, b.size() - 1);
                }
                
            } else {
                b = b + t[i];
            }
        }
        

        return a == b;
    }
};
