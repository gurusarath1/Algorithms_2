class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int ptr0 = 0;
        int ptr1 = 0;
        int num_zeros = 0;
        int max_window = 0;

        while(ptr1 <= nums.size() - 1) {

            if(nums[ptr1] == 1) {
                ptr1++;
                max_window = max(ptr1 - ptr0, max_window);
            } else {
                if(num_zeros == 0) {
                    ptr1++;
                    num_zeros = 1;
                    max_window = max(ptr1 - ptr0, max_window);
                } else {
                    if(nums[ptr0] == 0) {
                        num_zeros = 0;
                    }
                    ptr0++;
                }
            }
        }

        return max_window - 1;
        
    }
};
