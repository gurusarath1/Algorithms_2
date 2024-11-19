class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        map<int,int> vals_in_window;

        long long current_sum = 0;
        long long max_sum = 0;
        for(int i=0; i<nums.size(); i++) {
            if(i < k) {
                vals_in_window[nums[i]] += 1;
                current_sum += nums[i];
            } else {
                vals_in_window[nums[i]] += 1;
                current_sum += nums[i];
                vals_in_window[nums[i-k]] -= 1;
                current_sum -= nums[i-k];
                if(vals_in_window[nums[i-k]] == 0) {
                    vals_in_window.erase(nums[i-k]);
                }
            }

            if(vals_in_window.size() == k) {
                if(max_sum < current_sum) max_sum = current_sum;
            }
        }
        
        return max_sum;
    }
};
