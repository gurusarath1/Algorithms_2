class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int start = 0;
        int end = 0;
        int num_zeros = 0;
        int result = 0;
        int end_inced = 0;
        
        while(1) {
            
            if(nums[end] == 0) {
                
                if(num_zeros >= k) {
                    while(nums[start] != 0) {
                        start++;
                    }
                    start++;
                    num_zeros--;
                    
                    result = max(result, end - start + 1);
                    
                } else {
                    num_zeros++;
                    end_inced = 0;
                    if(end < nums.size() - 1) { end_inced = 1; end++; }
                    if(end_inced && nums[end] == 0 && num_zeros >= k)
                        result = max(result, end - start);
                    else
                        result = max(result, end - start+1);
                }
                
                
            } else {
                    end_inced = 0;
                    if(end < nums.size() - 1) { end_inced = 1; end++; }
                
                if(end_inced && nums[end] == 0 && num_zeros >= k)
                    result = max(result, end - start);
                else
                    result = max(result, end - start+1);
            }
            
            
            
            if(end == nums.size() - 1) break;
            
        }
        
        return result;
    }
};
