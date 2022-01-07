class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        map<char,int> dictX;
        set<char> unique_chars;
        int result = 0;
        int start = 0;
        
        for(int end=0; end < s.size(); end++) {
            
            if(end < k) {
                unique_chars.insert(s[end]);
                dictX[s[end]]++;
                
                if(end == k-1) {
                    if(unique_chars.size() == k) {
                        result++;
                    }
                }
                
            } else {
                
                if(dictX[s[start]] == 1) {
                    unique_chars.erase(s[start]);
                }
                dictX[s[start]]--;
                start++;
                
                unique_chars.insert(s[end]);
                dictX[s[end]]++;
                
                if(unique_chars.size() == k) {
                    result++;
                }
            }
            
        }
        
        return result;
        
    }
};
