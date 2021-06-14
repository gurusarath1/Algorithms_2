class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int min_forward = INT_MAX;
        int max_backward = INT_MIN;
        
        for(int i=1; i<nums.size(); i++) {
            
            if(nums[i] < nums[i-1]) {
                min_forward = min(nums[i], min_forward);
            }
        }
        
        for(int i=nums.size() - 2; i >= 0; i--) {
            if(nums[i+1] < nums[i]) {
                max_backward = max(nums[i], max_backward);
            }
        }
        
        if(min_forward ==  INT_MAX && max_backward == INT_MIN) return 0;
        
        int start = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > min_forward) {
                start = i;
                break;
            }
        }

        int end = 0;
        for(int i=nums.size() - 1; i >= 0; i--) {
            if(nums[i] < max_backward) {
                end = i;
                break;
            }
        }
        
        return end - start + 1;
        
    }
};
