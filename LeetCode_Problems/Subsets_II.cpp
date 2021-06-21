class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> subsets;
        subsets.push_back(vector<int>{});
        subsets.push_back(vector<int>{nums[0]});
        
        vector<vector<int>>temp = {{nums[0]}};
        
        for(int i=1; i<nums.size(); i++) {
            
            if(nums[i-1] != nums[i]) temp = subsets;
            
            for(int j=0; j<temp.size(); j++) {
                temp[j].push_back(nums[i]);
            }
            
            for(int j=0; j<temp.size(); j++) {
                subsets.push_back(temp[j]);
            }
            
        }
        
        return subsets;
        
        
    }
};
