class Solution {
public:
    
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    void rev(vector<int> &nums, int start, int end) {
        while(start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            
            start++;
            end--;
        }
    }
    
    
    void nextPermutation(vector<int>& nums) {
        
        int i = nums.size() - 1;
        bool desc_found = false;
        while(i-1 >=0) {
            if(nums[i] > nums[i-1]) {
                i--;
                desc_found = true;
                break;
            }
            i--;
        }
        
        if(!desc_found) {
            rev(nums, 0, nums.size() -1);
            return;
        }
        
        int j;
        for(j=i+1; j<nums.size(); j++) {
            
            if(nums[j] <= nums[i]) {
                j--;
                break;
            }
            
            if(j == nums.size() - 1) {
                break;
            }
        }
        
        swap(nums[i], nums[j]);
        
        rev(nums, i+1, nums.size() -1);
    }
};
