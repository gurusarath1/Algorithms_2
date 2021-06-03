class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string, vector<string>> anagram_groups_table;
        vector<vector<string>> return_groups;
        
        for(string str : strs) {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            
            anagram_groups_table[sorted_str].push_back(str);            
        }
        
        map<string, vector<string>>::iterator it = anagram_groups_table.begin();
        
        while(it != anagram_groups_table.end()) {
            
            return_groups.push_back(it->second);
            it++;
            
        }
        
        return return_groups;
        
    }
};
