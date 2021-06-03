class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int start_index = 0;
        int end_index = 0;
        
        int current_sum = 0;
        int min_window = nums.size() + 1;
        
        for(end_index = 0; end_index < nums.size(); end_index++) {
            
            current_sum += nums[end_index];
            
            while(current_sum >= target) {
                min_window = min(min_window, end_index - start_index + 1);
                current_sum -= nums[start_index];
                start_index++;
            }
            
        }
        
        return min_window == nums.size() + 1 ? 0 : min_window;
        
    }
};
