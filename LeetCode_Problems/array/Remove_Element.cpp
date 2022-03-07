class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int read_ptr = 0;
        int write_ptr = 0;
        int num_deletions = 0;
        for(; read_ptr<nums.size(); read_ptr++) {
            
            if(nums[read_ptr] == val) {
                num_deletions++;
                continue;
            } else {
                nums[write_ptr++] = nums[read_ptr];
            }
            
        }
        
        return nums.size() - num_deletions;
        
    }
};
