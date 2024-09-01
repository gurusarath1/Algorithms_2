class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int ptr1 = 0;
        int ptr2 = 0;
        int num_zeros_in_window = 0;
        int ans = 0;

        while(ptr2 < nums.size()) {

            if(nums[ptr2] == 1 && num_zeros_in_window <= k) { // 1
                ptr2 ++;
                ans = max(ans, ptr2 - ptr1);
            } else if(nums[ptr2] == 1) { // 1
                ptr2 ++;
                if(nums[ptr1] == 0) {
                    num_zeros_in_window--;
                }
                ptr1 ++;
            } else { // 0

                if(num_zeros_in_window < k) {
                    num_zeros_in_window++;
                    ptr2++;
                    ans = max(ans, ptr2 - ptr1);
                } else {
                    num_zeros_in_window++;
                    ptr2++;
                    if(nums[ptr1] == 0) {
                        num_zeros_in_window--;
                    }
                    ptr1++;

                }

            }

        }

        return ans;
        
    }
};
