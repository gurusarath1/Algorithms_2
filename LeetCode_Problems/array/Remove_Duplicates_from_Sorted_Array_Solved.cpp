class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int insert_idx = 0;
        int run_idx = insert_idx+1;
        int n = nums.size();

        // Invariant: run_idx > insert_idx
        while(run_idx < n) {

            if(nums[run_idx] == nums[insert_idx]) {
                // If duplicates found, skip all duplicates
                while(run_idx < n  && nums[run_idx] == nums[insert_idx]) {
                    run_idx++;
                }

                // After skipping duplicates, copy the new element
                if(run_idx >= n) {
                    break; // array ended
                } else {
                    insert_idx++;
                    nums[insert_idx] = nums[run_idx];
                }
            } else {
                // Check next
                insert_idx++;
                run_idx++;
            }

        }
        
        return insert_idx+1;
    }
};
