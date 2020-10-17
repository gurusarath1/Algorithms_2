/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> result;
        
        generateParenthesis_support(n*2, 0, 0, 0, "", result);
        
        return result;
        
    }
    
    void generateParenthesis_support(int max_depth, int current_depth, int num_open_parentheses_current, int num_started_parentheses_set, string built_string, vector<string>& result) {
        
        /*
          max_depth - Number of charecters in the return string = Number of sets * 2 (open and close parentheses)
          num_open_parentheses_current - Numbers of brackets opened so far
          num_started_parentheses_set - Number of brackets groups started / started and closed
        */
        
        if(current_depth == max_depth) {
            result.push_back(built_string);
            return;
        }
        
        // Open a paranthesis only if you have not opened enough sets
        if(num_open_parentheses_current < (max_depth/2) && num_started_parentheses_set < (max_depth/2))
            generateParenthesis_support(max_depth, current_depth+1, num_open_parentheses_current+1, num_started_parentheses_set+1, built_string+"(", result);
        
        // Close parentheses only if there are any open parentheses
        if(num_open_parentheses_current > 0)
            generateParenthesis_support(max_depth, current_depth+1, num_open_parentheses_current-1, num_started_parentheses_set, built_string+")", result);
    }
};
