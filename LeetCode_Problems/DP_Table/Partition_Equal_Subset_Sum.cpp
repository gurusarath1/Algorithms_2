class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int half_sum = 0;
        for(int x : nums) half_sum += x;
        if(half_sum % 2 != 0) return false; //Cannot add up numbers to get a decimal (because we have only integers)
        half_sum = half_sum / 2;
        
        vector<vector<bool>> dp(nums.size(), vector<bool>(half_sum+1, false));
        
        for(int sum=0; sum<dp[0].size(); sum++) {
            if(sum == nums[0] || sum == 0) {
                dp[0][sum] = true;
            }
        }
        
        for(int include_nums=1; include_nums<dp.size(); include_nums++) {
            dp[include_nums][0] = true;
        }
        
        
        for(int include_nums=1; include_nums<dp.size(); include_nums++) {
            for(int sum=1; sum<dp[0].size(); sum++) {
                if(dp[include_nums - 1][sum]) dp[include_nums][sum] = true; 
                
                if(sum - nums[include_nums] >= 0 && dp[include_nums - 1][sum - nums[include_nums]]) dp[include_nums][sum] = true; 
                      
            }
        }
        
        return dp[nums.size() - 1][sumX];
        
    }
};
