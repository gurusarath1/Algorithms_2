class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        map<char,int> dictX;
        set<char> unique_ints;
        int result = 0;
        int start = 0;
        
        for(int end=0; end < s.size(); end++) {
            
            if(end < k) {
                unique_ints.insert(s[end]);
                dictX[s[end]]++;
                
                if(end == k-1) {
                    if(unique_ints.size() == k) {
                        result++;
                    }
                }
                
            } else {
                
                if(dictX[s[start]] == 1) {
                    unique_ints.erase(s[start]);
                }
                dictX[s[start]]--;
                start++;
                
                unique_ints.insert(s[end]);
                dictX[s[end]]++;
                
                if(unique_ints.size() == k) {
                    result++;
                }
            }
            
        }
        
        return result;
        
    }
};
