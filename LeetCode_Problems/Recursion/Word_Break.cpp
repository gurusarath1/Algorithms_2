class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        set<string> wordSet;
        map<string, bool> memo;
        
        for(string x : wordDict) {
            wordSet.insert(x);
        }
        
        bool result = support_wordBreak(s, wordSet, memo);
        
        return result;
    }
    
    bool support_wordBreak(string s, set<string> &wordSet, map<string, bool> &memo) {
        
        if(s.size() == 0) return true;

        if(memo.find(s) != memo.end()) {
            return memo[s];
        }
        
        for( int str_length=1; str_length <= s.size(); str_length ++) {
            
            string x = s.substr(0, str_length);
            
            if(wordSet.find(x) != wordSet.end()) {
                
                string remainingString = s.substr(str_length, s.size() - str_length);
                bool result = support_wordBreak(remainingString, wordSet, memo);
                
                if(result) memo[remainingString] = true;
                
                if(result) return true;
            }
            
        }
        
        memo[s] = false;
        
        return false;
        
    }
};
