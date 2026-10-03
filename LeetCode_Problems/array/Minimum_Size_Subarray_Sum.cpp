class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int win_start = 0;
        int win_end = 0;
        int min_len = INT_MAX;
        long long curr_sum = 0;

        for(win_end=0; win_end<nums.size(); win_end++) {
            curr_sum += nums[win_end];

            // Shrink the size of window if current sum exceeds
            while(curr_sum >= target) {
                int curr_len = win_end - win_start + 1;
                if(min_len > curr_len) {
                    min_len = curr_len;
                }
                curr_sum -= nums[win_start];
                win_start++;
            }
        }

        if(min_len == INT_MAX) return 0;
        
        return min_len;
    }
};
