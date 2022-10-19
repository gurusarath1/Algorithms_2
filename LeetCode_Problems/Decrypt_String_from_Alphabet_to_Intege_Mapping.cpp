class Solution {
public:
    string freqAlphabets(string s) {
        
        string out_string = "";
        
        for(int i=0; i<s.size(); i++) {
            
            char current_char = s[i];
            
            if(current_char > '2') {
                // type 1
                out_string += 'a' + current_char - '1';
            } else {
                // type 1 or 2
                
                if(i+2 < s.size() &&  s[i+2] == '#') {
                    //type 2
                    int offset = (s[i] - '0')*10 + (s[i+1] - '0') - 1;
                    out_string += 'a' + offset;
                    i += 2;
                } else {
                    //type 1
                    out_string += 'a' + current_char - '1';
                }
                
            }
            
            
        }
        
        
        return out_string;
        
    }
};
