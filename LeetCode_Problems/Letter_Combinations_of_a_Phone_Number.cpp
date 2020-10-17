/*

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]

*/


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        map<char, string> numpad;
        numpad['0'] = " ";
        numpad['1'] = "";
        numpad['2'] = "abc";
        numpad['3'] = "def";
        numpad['4'] = "ghi";
        numpad['5'] = "jkl";
        numpad['6'] = "mno";
        numpad['7'] = "pqrs";
        numpad['8'] = "tuv";
        numpad['9'] = "wxyz";
        
        vector<string> result;
        
        if(digits == "") return result;
        
        letterCombinations_support(digits, 0, numpad, result, "");
        
        return result;
    }
    
    void letterCombinations_support(string& digits, int current_digit_index, map<char, string>& numpad, vector<string>& result, string built_string) {
        
        if(current_digit_index >= digits.size()) result.push_back(built_string);
        
        for(char letter : numpad[digits[current_digit_index]]) {
            letterCombinations_support(digits, current_digit_index+1, numpad, result, built_string + letter);
        }
        
    }
};
