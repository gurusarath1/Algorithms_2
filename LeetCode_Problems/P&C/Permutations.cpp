class Solution {
public:
    
    vector<vector<int>> result;
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        permute_support(nums, 0);
        
        return result;
        
    }
    
    void swap(int &a, int &b) {
        int temp =a;
        a = b;
        b = temp;
    }
    
    void permute_support(vector<int>& nums, int index) {
        
        if(index >= nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for(int i=index; i<nums.size(); i++) {
            swap(nums[index], nums[i]);
            permute_support(nums, index+1);
            swap(nums[index], nums[i]); // Undo swap before the next iter
        }
        
    }
    
};
