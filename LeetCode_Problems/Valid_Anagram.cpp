/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

*/



// Method 1
// Sort both the strings and check if they are equal 

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size())
        {
            return false;
        }
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        if(s == t)
        {
            return true;
        } else {
            return false;
        }   
    }
};

// Method 2
// Use a Hash map and count the number of number of times each character repeats
// Check if both the maps are same

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
        {
            return false;
        }
        
        map<char, int> s_char_count;
        map<char, int> t_char_count;
        for(int i=0; i<s.size(); i++)
        {
            s_char_count[s[i]] += 1;
            t_char_count[t[i]] += 1;
        }
        
        if(s_char_count == t_char_count)
        {
            return true;
        } else {
            return false;
        }   
    }
};
