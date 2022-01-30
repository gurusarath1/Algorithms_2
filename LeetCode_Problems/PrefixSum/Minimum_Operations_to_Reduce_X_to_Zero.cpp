class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int sum = 0;
        for(int num : nums) {
            sum += num;
        }
        
        
        int compliment_sum = sum - x;
        
        if(compliment_sum == 0) {
            // YOu need the whole array to make x 0
            return nums.size();
        }
        
        map<int, int> sum_first_index;
        
        sum_first_index[0] = -1;
        int size_of_subarray = 0;
        int max_size_of_subarray = 0;
        
        // Find sub array sum
        sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];

            if(sum_first_index.find(sum - compliment_sum) != sum_first_index.end()) {
                size_of_subarray = i - sum_first_index[sum - compliment_sum];
                
                // Find max length possible sub array
                if(max_size_of_subarray < size_of_subarray) max_size_of_subarray = size_of_subarray;
            }

            if(sum_first_index.find(sum) == sum_first_index.end()) {
                sum_first_index[sum] = i;
            }
            
        }
        
        if(max_size_of_subarray == 0) return -1;
        
        return nums.size() - max_size_of_subarray;
        
    }
};
