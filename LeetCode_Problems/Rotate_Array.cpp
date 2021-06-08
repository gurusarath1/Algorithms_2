class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int temp;
        
        k = k % nums.size();
        
        // Reverse the whole array
        int ptr1 = 0;
        int ptr2 = nums.size() - 1;
        while(ptr1 < ptr2) {
            
            temp = nums[ptr1];
            nums[ptr1] = nums[ptr2];
            nums[ptr2] = temp;
            
            ptr1++;
            ptr2--;
            
        }
        
        // Reverse the first k elements
        ptr1 = 0;
        ptr2 = k - 1;
        while(ptr1 < ptr2) {
            
            temp = nums[ptr1];
            nums[ptr1] = nums[ptr2];
            nums[ptr2] = temp;
            
            ptr1++;
            ptr2--;
            
        }
        
        // reverse the next num.size() - k elements
        ptr1 = k;
        ptr2 = nums.size() - 1;
        while(ptr1 < ptr2) {
            
            temp = nums[ptr1];
            nums[ptr1] = nums[ptr2];
            nums[ptr2] = temp;
            
            ptr1++;
            ptr2--;
            
        }
    }

};
