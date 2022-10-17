class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        for(int current_pos=0, last_non_zero_pos=0; current_pos<nums.size(); current_pos++) {
            
            if(nums[current_pos] != 0) {
                // Swap
                int temp = nums[current_pos];
                nums[current_pos] = nums[last_non_zero_pos];
                nums[last_non_zero_pos] = temp;
                
                last_non_zero_pos++;
            }
        }
    }
};
