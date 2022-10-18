class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string result = "";
        
        int count1 = 0;
        int count2 = 0;
        
        while(count1 < word1.size() && count2 < word2.size()) {
            
            result += word1[count1];
            result += word2[count2];
            
            count1++;
            count2++;
        }
        
        while(count1 < word1.size()) {
            result += word1[count1];
            count1++;
        }

        while(count2 < word2.size()) {
            result += word2[count2];
            count2++;
        }
        
        return result;
    }
};
