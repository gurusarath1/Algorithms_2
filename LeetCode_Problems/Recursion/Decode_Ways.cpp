class Solution {
public:
    int numDecodings(string s) {
        unordered_map<int,int> memo;
        return support_numDecoding(-1, s, memo);
    }
    
    int support_numDecoding(int index, string s, unordered_map<int,int> &memo) {
        
        
        if(memo[index] == -1) {
            return 0;
        }
        
        if(memo[index] > 0) {
            return memo[index];
        }
        
        
        if(index == s.size() - 1) {
            memo[index] = 1;
            return 1;
        }
        
        int ways1 = 0;
        int ways2 = 0;
        
        if(index + 1 < s.size() && s[index + 1] != '0') {
            ways1 = support_numDecoding(index + 1, s, memo);
        }
        
        if(index + 2 < s.size()) {
            int numX = (s[index + 1] - '0') * 10 + s[index + 2] - '0';
            if(s[index + 1] != '0' && numX <= 26 ) {
                ways2 = support_numDecoding(index + 2, s, memo);
            }
        }
        
        int ways =  ways1 + ways2;
        
        memo[index] = ways;
        
        return ways;
        
    }
    
};
