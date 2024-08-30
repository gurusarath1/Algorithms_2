class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int ptr1 = 0;
        int ptr2 = nums.size() - 1;
        int ops = 0;

        while(ptr1 < ptr2) {

            if( (nums[ptr1] + nums[ptr2]) == k ) {
                ptr1++;
                ptr2--;
                ops++;
            } else if( (nums[ptr1] + nums[ptr2]) > k ) {
                ptr2--;
            } else {
                ptr1++;
            }

        }
        
        return ops;
    }
};
