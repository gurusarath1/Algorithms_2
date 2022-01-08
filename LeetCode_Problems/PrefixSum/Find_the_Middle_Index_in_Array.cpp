class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        
        vector<int> prefixSum(nums.size());
        vector<int> suffixSum(nums.size());
        int sum_prefix = 0;
        int sum_suffix = 0; 
        
        int j;
        for(int i=0, j=nums.size()-1; i < nums.size(); i++, j--) {
            
            sum_prefix += nums[i];
            sum_suffix += nums[j];
            
            prefixSum[i] = sum_prefix;
            suffixSum[j] = sum_suffix;
            
        }
        
        for(int i=0; i<nums.size(); i++) {
            if(prefixSum[i] == suffixSum[i]) return i;
        }
        
        return -1;
    }
};
