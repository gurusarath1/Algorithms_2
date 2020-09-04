/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size() == 0) {
            return "";
        }
        
        int min_size = INT_MAX;
        for(string x : strs) {
            if(x.size() < min_size) {
                min_size = x.size();
            }
        }
        
        if(min_size == 0) {
            return "";
        }
        
        char char_to_match;
        int prefix_len = 0;
        for(int i=0; i<min_size; i++) {
            prefix_len = i;
            char_to_match = strs[0][i];
            for(int k=1; k<strs.size(); k++) {
                
                if(char_to_match != strs[k][i]) {
                    
                    return strs[0].substr(0,prefix_len);
                }
            }
        }
        
        return strs[0].substr(0,prefix_len+1);
        
    }
};
