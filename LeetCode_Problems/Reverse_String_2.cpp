class Solution {
public:
    void reverseString(vector<char>& s) {
        
        vector<char> s_reversed;
        
        reverseString_support(s, 0, s_reversed);
        s = s_reversed;
        
    }
    
    void reverseString_support(vector<char>& s, int index, vector<char>& s_reversed) {
        
        if(index >= s.size()) {
            return;
        }
        
        reverseString_support(s, index+1, s_reversed);
        s_reversed.push_back(s[index]);
        
    }
};
