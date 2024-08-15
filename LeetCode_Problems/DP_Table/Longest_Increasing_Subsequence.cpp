class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> dp(nums.size(), 1);
        int max_seq_len = 1;

        for(int end_index=1; end_index < nums.size(); end_index++) {

            for(int start_index=end_index-1; start_index >= 0; start_index--) {
                if(nums[start_index] < nums[end_index]) {
                    dp[end_index] = max(dp[end_index], dp[start_index] + 1);
                    max_seq_len = max(dp[end_index], max_seq_len);
                }
            }

        }

        return max_seq_len;
    }
};
