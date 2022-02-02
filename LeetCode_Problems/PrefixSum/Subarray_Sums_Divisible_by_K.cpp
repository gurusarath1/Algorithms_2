class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        vector<int> prefixSum(nums.size(), 0);
        int sum = 0;
        map<int,int> mod_index;
        mod_index[0] = 1;
        int mod;
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            prefixSum[i] = sum;
            
            mod = sum % k;
            if(mod < 0) mod = k + mod; // Handle the negative case of mod
            
            if( mod_index.find(mod) != mod_index.end() ) {
                count += mod_index[mod];
            }
            
            mod_index[mod] += 1;
            
        }
        
        return count;
        
    }
};
