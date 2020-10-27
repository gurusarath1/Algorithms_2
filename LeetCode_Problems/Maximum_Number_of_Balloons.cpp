/*
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
You can use each character in text at most once. Return the maximum number of instances that can be formed.

Example 1:
Input: text = "nlaebolko"
Output: 1

Example 2:
Input: text = "loonbalxballpoon"
Output: 2

Example 3:
Input: text = "leetcode"
Output: 0
*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        map<char, int> occurances;
        
        occurances['b'] = 0;
        occurances['a'] = 0;
        occurances['l'] = 0;
        occurances['o'] = 0;
        occurances['n'] = 0;
        
        for(char c : text) {
            if(c == 'b' || c == 'a' || c == 'l' || c == 'o' || c == 'n') occurances[c] = occurances[c] + 1;
        }
        
        map<char, int>::iterator iter = occurances.begin();
        int min = INT_MAX;
        int count;
        while(iter != occurances.end()) {
            
            if(iter->second == 0) return 0;
            
            if(iter->first == 'l' || iter->first == 'o') {
                count = iter->second / 2;
            } else {
                count = iter->second;
            }
            
            if(count < min) {
                min = count;
            }
            
            iter++;
        }
        
        return min;
        
    }
};
