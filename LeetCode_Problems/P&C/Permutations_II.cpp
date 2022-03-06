class Solution {
public:
    
    vector<vector<int>> result;
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        support_permuteUnique(nums, 0);
        
        return result;
        
    }
    
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    void support_permuteUnique(vector<int> &nums, int index) {
        if(index == nums.size() - 1) {
            result.push_back(nums);
        }
        
        set<int> seen;
        for(int i = index; i<nums.size(); i++) {
            
            if(seen.find(nums[i]) != seen.end()) continue; // Don't make the same swap
            
            seen.insert(nums[i]);
            swap(nums[index], nums[i]);
            
            support_permuteUnique(nums, index+1);
            
            swap(nums[index], nums[i]);
        }
    }
};
