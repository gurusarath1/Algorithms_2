class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        vector<int> prefixSum(nums.size());
        map<int, int> mod_index;
        
        mod_index[0] = -1;
        
        prefixSum[0] = nums[0];
        if(prefixSum[0] % k != 0) mod_index[prefixSum[0] % k] = 0;
        
        for(int i=1; i<nums.size(); i++) {
            prefixSum[i] += prefixSum[i-1] + nums[i];
            
            cout << prefixSum[i] << "  " << prefixSum[i] % k << endl;
            
            if( mod_index.find(prefixSum[i] % k) != mod_index.end() ) {
                if( i - mod_index[prefixSum[i] % k] >= 2) return true;
            } else mod_index[prefixSum[i] % k] = i;
            
        }
        
        return false;
        
    }
};
