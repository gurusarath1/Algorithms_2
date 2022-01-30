class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int, vector<int>> sum_indices;
        vector<int> prefix_sum(nums.size(), 0);
        int count = 0;
        
        sum_indices[0].push_back(-1);
        
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            prefix_sum[i] = sum;
            
            if(sum_indices.find(prefix_sum[i] - k) != sum_indices.end()) {
                count += sum_indices[prefix_sum[i] - k].size();
                
                /* Print sub arrays indices
                for(int start_index : sum_indices[prefix_sum[i] - k]) {
                    cout << "(" << start_index + 1 << ", " << i << ")" << endl;
                }
                */
            }
            
            sum_indices[prefix_sum[i]].push_back(i);
        }
        
        return count;
        
    }
};
