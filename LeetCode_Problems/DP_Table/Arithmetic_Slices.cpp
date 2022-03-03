class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        if(nums.size() <= 2) {
            return 0;
        }
        
        vector<int> dp(nums.size(), 0);
        
        int num_aps = 0;
        for(int i=2; i<=nums.size()-1; i++) {
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                dp[i] = dp[i-1] + 1;
                num_aps += dp[i];
            } else {
                dp[i] = 0;
            }
        }
        
        return num_aps;
        
    }
};
