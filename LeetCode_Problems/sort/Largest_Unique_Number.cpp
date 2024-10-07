class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        for(int i=nums.size()-1; i>=0; ) {

            int repeat_steak = 0;
            while(i >= 1 && (nums[i] == nums[i-1]) ) {
                i--;
                repeat_steak =1;
            }

            if(repeat_steak) {
                i--;
            } else {
                return nums[i];
            }
        }

        return -1;
        
    }
};
