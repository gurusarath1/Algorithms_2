class Solution {
public:
    bool canSortArray(vector<int>& nums) {

        for(int end=nums.size()-2; end >= 0; end--) {
            for(int i=0; i<=end; i++) {
                if(nums[i] > nums[i+1]) {
                    if(num_set_bits(nums[i]) != num_set_bits(nums[i+1])) {
                        return false;
                    } else {
                        int temp = nums[i];
                        nums[i] = nums[i+1];
                        nums[i+1] = temp;
                    }
                }
            }
        }

        return true;
    }

    int num_set_bits(int num) {

        int count = 0;
        while(num) {
            num = num & (num - 1);
            count++;
        }

        return count;
    }
};
