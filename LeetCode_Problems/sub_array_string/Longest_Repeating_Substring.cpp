/*
Given a string s, return the length of the longest repeating substrings.
If no repeating substring exists, return 0.
*/

class Solution {
public:
    int longestRepeatingSubstring(string s) {

        map<string, int> count;
        int max_len = 0;

        for(int i=0; i<s.size(); i++) { // Generate all substrings
            string sub_s = "";
            for(int j=i; j<s.size(); j++) {
                sub_s += s[j];
                count[sub_s] += 1;

                if(count[sub_s] > 1) {
                    if(sub_s.size() > max_len) max_len = sub_s.size();
                }
            }
        }

        return max_len;
    }
};
