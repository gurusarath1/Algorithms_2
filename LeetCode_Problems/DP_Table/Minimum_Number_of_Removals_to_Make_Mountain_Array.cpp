class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {

        vector<int> dp1(nums.size(), 1);
        vector<int> dp2(nums.size(), 1);

        for(int i=0; i<nums.size(); i++) {
            for(int j=0; j<i; j++) {
                if(nums[j] < nums[i]) dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }

        for(int i=nums.size()-1; i>=0; i--) {
            for(int j=nums.size()-1; j>i; j--) {
                if(nums[j] < nums[i]) dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }

        int min_deletions = INT_MAX;
        for(int i=1; i<nums.size()-1; i++) {
            if(dp1[i] > 1 && dp2[i] > 1) {
                int num_deletions = nums.size() - dp1[i] - dp2[i] + 1 ;
                if(min_deletions > num_deletions) {
                    min_deletions = num_deletions;
                }
            }
        }

        return min_deletions;
    }
};
