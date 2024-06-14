class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int num_moves = 0;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] <= nums[i-1]) {
                num_moves += nums[i-1] - nums[i] + 1;
                nums[i] = nums[i-1] + 1;
            }
        }

        return num_moves;
    }
};
