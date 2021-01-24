/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s.
If there isn't one, return 0 instead.
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        
        int start_index, end_index = 0;
        int sum = 0;
        int minimun_size = INT_MAX;
        
        for(start_index = 0; start_index < nums.size(); start_index++) {
            
            while(sum < s && end_index < nums.size()) {
                sum += nums[end_index];
                end_index++;
            }
            
            if(sum >= s && minimun_size > end_index - start_index) {
                minimun_size = end_index - start_index;
            }
            
            sum -= nums[start_index];
            
        }
        
        if(minimun_size == INT_MAX) return 0;
        
        return minimun_size;
        
    }
};
