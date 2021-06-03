class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<vector<int>, vector<string>> anagram_groups_table;
        vector<vector<string>> return_groups;
        
        for(string str : strs) {
            
            vector<int> str_hash(26);
            for(char c : str) {
                str_hash[c - 'a'] = str_hash[c - 'a'] + 1;
            }
            
            anagram_groups_table[str_hash].push_back(str);            
        }
        
        map<vector<int>, vector<string>>::iterator it = anagram_groups_table.begin();
        
        while(it != anagram_groups_table.end()) {
            
            return_groups.push_back(it->second);
            it++;
            
        }
        
        return return_groups;
        
    }
};
