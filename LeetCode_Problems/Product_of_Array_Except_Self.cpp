class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> left_products(nums.size());
        vector<int> right_products(nums.size());
        vector<int> results(nums.size());
        
        
        // Generate the array of left products
        for(int i=0; i<nums.size(); i++) {
            
            if(i == 0) {
                left_products[i] = 1;                
            } else {
                left_products[i] = left_products[i - 1] * nums[i - 1];
            }
            
        }
        
        // Generate the array of right products
        for(int i=nums.size() - 1; i >=0; i--) {
            
            if(i == nums.size() - 1) {
                right_products[i] = 1;
            } else {
                right_products[i] = right_products[i + 1] * nums[i + 1];
            }
            
        }
        
        // Generate the final result
        for(int i=0; i<nums.size(); i++) {
            results[i] = left_products[i] * right_products[i];
        }
        
        return results;
        
    }
};
