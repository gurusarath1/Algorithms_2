class Solution {
public:

    // [lo, hi] -----
    int search(vector<int>& nums, int target) {
        
        int start_index = 0;
        int end_index = nums.size() - 1;
        int mid_index;
        
        while(start_index <= end_index) {
            
            mid_index = start_index + (end_index - start_index)/2;
            
            if(nums[mid_index] == target) {
                return mid_index;
            } else if(nums[mid_index] > target) {
                end_index = mid_index - 1;
            } else {
                start_index = mid_index + 1;
            }
            
        }
        
        return -1;
        
    }
};



class Solution {
public:

    // [lo, hi) -----
    int search(vector<int>& nums, int target) {

        int l = 0, h = nums.size(); // <---- diff

        while(l < h) { // <---- diff
            
            int m = l + (h - l) / 2;

            if(nums[m] < target) {
                l = m + 1;
                
            } else if (nums[m] > target){
                h = m; // <---- diff
                
            } else {
                return m;
            }
        }

        return -1;
        
    }
};
