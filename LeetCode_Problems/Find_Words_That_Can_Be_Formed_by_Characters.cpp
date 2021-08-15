class Solution {
public:
    
    map<char,int> char_counts;
    map<char,int> char_counts_2;
    
    int countCharacters(vector<string>& words, string chars) {
        
        int len = 0;
        
        for(char c : chars) {
            char_counts_2[c] = char_counts_2[c] + 1; 
        }
        
        for(string s : words) {
            
            bool possible = true;
            char_counts = char_counts_2;
            for(char c : s) {
                
                if(char_counts[c] <= 0) {
                    possible = false;
                    break;
                } else {
                    char_counts[c]--;
                }
                
            }
            
            if(possible) {
                len += s.size();
            }
            
        }
        
        return len;
        
    }
};
