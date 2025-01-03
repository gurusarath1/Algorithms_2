class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        int ans = 0;
        long long right_sum = 0;

        for(int n : nums) {
            right_sum += n;
        }

        long long left_sum = 0;
        for(int i=0; i<nums.size()-1; i++) {
            left_sum += nums[i];
            right_sum -= nums[i];

            if(left_sum >= right_sum) ans++;
        }

        return ans;
        
    }
};
