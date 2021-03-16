class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        
        int max_sub_arrays = 0;
        int prefix_sum = 0;
        int complement;
        int last_end = -1;
        map<int, int> prefixSum_map;
        
        prefixSum_map[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            prefix_sum += nums[i];
            complement = prefix_sum - target;

            if (prefixSum_map.find(complement) != prefixSum_map.end()) {
                // sub-array found
                //cout << "[ " << prefixSum_map[complement] + 1 << " , " << i << " ]";
                
                if(last_end < prefixSum_map[complement] + 1) {
                    max_sub_arrays++;
                    last_end = i;
                }

            }
            
            prefixSum_map[prefix_sum] = i;
        }
        
        return max_sub_arrays;
        
    }
};
