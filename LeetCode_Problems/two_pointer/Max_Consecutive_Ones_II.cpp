/*
Given a binary array nums, return the maximum number of consecutive 1's in the array if you can flip at most one 0.
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int zeros = 0;
        int max_len = 0;

        while(r < nums.size()) {
            int num = nums[r];

            while(num == 0 && zeros == 1) {
                if(nums[l] == 0) zeros -= 1;
                l++;
            }

            if(num == 0) {
                zeros += 1;
            }

            int len = r - l + 1;

            if(len > max_len) {
                max_len = len;
            }

            r++;
        }

        return max_len;
    }
};
