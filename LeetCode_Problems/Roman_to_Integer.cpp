class Solution {
public:
    int romanToInt(string s) {
        
        map<char, int> roman_to_int_map;
        
        roman_to_int_map['I'] = 1;
        roman_to_int_map['V'] = 5;
        roman_to_int_map['X'] = 10;
        roman_to_int_map['L'] = 50;
        roman_to_int_map['C'] = 100;
        roman_to_int_map['D'] = 500;
        roman_to_int_map['M'] = 1000;
        
        int value = 0;
        
        for(int i=0; i<s.size(); i++) {
            
            if(i < s.size() - 1){
                if(roman_to_int_map[s[i]] < roman_to_int_map[s[i+1]]){
                    value -= roman_to_int_map[s[i]];
                } else {
                    value += roman_to_int_map[s[i]];
                }
            } else {
                value += roman_to_int_map[s[i]];
            }
            
        }
        
        return value;
        
    }
};
