/*
Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:
s = "leetcode"
return 0.

s = "loveleetcode"
return 2.

Note: You may assume the string contains only lowercase English letters.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        
        map<char,int> char_index;
        
        for(int i=0; i<s.size(); i++)
        {
            if(char_index[s[i]] > 0)
            {
                char_index[s[i]] = -1;
            } else if(char_index[s[i]] == -1)
            {
                ;
            } else {
                char_index[s[i]] = i + 1;
            }
        }
        
        map<char,int>::iterator p = char_index.begin();
        int min = INT_MAX;
        while( p != char_index.end() )
        {
            cout << p->second << "\n";
            if(p->second != -1 && p->second < min)
            {
                min = p->second;
            }
            
            p++;
        }
        
        if(min == INT_MAX)
            return -1;
        else
            return min - 1;
        
    }
};
