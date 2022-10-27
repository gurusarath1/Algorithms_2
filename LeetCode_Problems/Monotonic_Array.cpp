class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        int comp_prev = -1, comp_current;
        for(int i=1; i<nums.size(); i++) {
            
            if(nums[i-1] < nums[i]) {
                comp_current = 1; // Greater
            } else if (nums[i-1] > nums[i]) {
                comp_current = 2; // Lesser
            } else {
                comp_current = 0; // Equal
            }
            
            if(comp_current == 0) continue;
            
            // comp_prev = -1 indicates that we are in the first pair of unequal elements
            if(comp_prev == -1 || comp_current == comp_prev) {
                comp_prev = comp_current;
                continue;
            }
            
            return false;
        }
        
        return true;
    }
};
