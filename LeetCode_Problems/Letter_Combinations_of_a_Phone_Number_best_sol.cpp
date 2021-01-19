/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        if(digits == "") {
            return vector<string>();
        }
        
        vector<string> keypad;
        
        keypad.push_back(" ");  // 0
        keypad.push_back("");  // 1
        keypad.push_back("abc");  // 2
        keypad.push_back("def");  // 3
        keypad.push_back("ghi");  // 4
        keypad.push_back("jkl");  // 5
        keypad.push_back("mno");  // 6
        keypad.push_back("pqrs");  // 7
        keypad.push_back("tuv");  // 8
        keypad.push_back("wxyz");  // 9
        
        vector<string> result;
        string empty_string = "";
        
        letterCombinations(digits, 0, empty_string, keypad, result);
        
        return result;
        
    }
    
    void letterCombinations(string &digits, int current_index, string &current_string, vector<string> &keypad, vector<string> &result) {
        
        if(current_index >= digits.size()) {
            result.push_back(current_string);
            return;
        }
        
        
        for(char c : keypad[digits[current_index] - '0']) {
            
            current_string = current_string + c;
            letterCombinations(digits, current_index+1, current_string, keypad, result);
            current_string = current_string.substr(0, current_index);
            
        }
        
        return;
        
        
    }
};
