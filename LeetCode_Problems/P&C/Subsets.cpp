class Solution {
public:
    
    vector<vector<int>> result;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        recurse(nums, vector<int>{}, 0);
        
        return result;
    }
    
    void recurse(vector<int>& nums, vector<int> picks, int i) {
        
        if(i >= nums.size()) {
            result.push_back(picks);
            return;
        }
        
        recurse(nums, picks, i+1);
        
        picks.push_back(nums[i]);
        recurse(nums, picks, i+1);
        
    }
};
