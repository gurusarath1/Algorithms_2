class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        vector<bool> dp(nums.size(), false);
        
        dp[nums.size() - 1] = true;
        
        for(int i=nums.size() - 2; i >= 0; i--) {
            
            for(int jump=1; jump<=nums[i]; jump++) {
                if(i + jump > nums.size() - 1) break;
                if(dp[i +jump]) {
                    dp[i] = true;
                    break;
                }
            }
            
        }
        
        return dp[0];
        
    }
};
