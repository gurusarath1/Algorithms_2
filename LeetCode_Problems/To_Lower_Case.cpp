class Solution {
public:
    string toLowerCase(string s) {
        
        string lower_str = "";
        
        for(char c : s) {
            if(c >= 'A' && c <= 'Z') {
                // Upper to lower
                lower_str += (c + 32);
            } else {
                // Stay lower or stay special char
                lower_str += c;
            }
        }
        
        return lower_str;
        
    }
};
