class Solution {
public:
    int jump(vector<int>& nums) {
        
        vector<int> dp(nums.size(), -1);

        dp[nums.size() - 1] = 0;
        
        for(int i=nums.size()-2; i >= 0; i--) {
            
            int min_jump = INT_MAX;
            for(int jump=1; jump<=nums[i]; jump++) {
                if(i+jump >= nums.size()) break;
                if(dp[i+jump] >= 0) {
                    min_jump = min(min_jump, dp[i+jump] + 1);
                }
            }
            
            if(min_jump == INT_MAX) {
                dp[i] = -1;
            } else {
                dp[i] = min_jump;
            }
            
        }
        
        return dp[0];
        
    }
};
