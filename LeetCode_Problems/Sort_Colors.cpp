class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int pointer1 = 0; // Pointer to store 0s
        int pointer2 = nums.size() - 1; // Pointer to store 2s
        
        int i = 0;
        while(i <= pointer2) { // numbers beyond pointer2 are 2s so no need to proceed
            
            if(nums[i] == 0) {
                nums[i] = nums[pointer1];
                nums[pointer1] = 0;
                pointer1++;
                i++;
            } else if(nums[i] == 2) {
                nums[i] = nums[pointer2];
                nums[pointer2] = 2;
                pointer2--;
                // OBSERVE THAT WE DONT INCREMENT i here
            } else {
                i++;
            }
            
        }
        
    }
};
