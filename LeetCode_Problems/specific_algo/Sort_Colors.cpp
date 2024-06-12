class Solution {
public:

    void swap_nums(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void sortColors(vector<int>& nums) {

        int p = 0;
        int p0 = 0;
        int p2 = nums.size() - 1;

        while(p2 >= p) {


            if(nums[p]  == 0) {
                swap_nums(nums[p], nums[p0]);
                p++;
                p0++;
            } else if(nums[p] == 2) {
                swap_nums(nums[p], nums[p2]);
                p2--;
            } else {
                p++;
            }

        }

    }
};
