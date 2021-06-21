class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> subsets;
        vector<int> empty_set;
        
        subsets.push_back(empty_set);
        
        for(int x : nums) {
            vector<vector<int>> temp_sets = subsets;
            
            for(int i=0; i<temp_sets.size(); i++) {
                temp_sets[i].push_back(x);
            }
            
            for(int i=0; i<temp_sets.size(); i++) {
                subsets.push_back(temp_sets[i]);
            }
            
        }
        
        return subsets;
        
    }
};
