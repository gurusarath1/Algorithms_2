class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int dp[nums1.size() + 1][nums2.size() + 1];
        
        for(int i=0; i<nums1.size()+1; i++) {
            dp[i][0] = 0;
        }
        
        for(int i=0; i<nums2.size()+1; i++) {
            dp[0][i] = 0;
        }
        
        int max_len = 0;
        for(int i=1; i<nums1.size()+1; i++) {
            for(int j=1; j<nums2.size()+1; j++) {
                if(nums1[i-1] == nums2[j - 1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    if(dp[i][j] > max_len) max_len = dp[i][j];
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return max_len;
        
    }
};
