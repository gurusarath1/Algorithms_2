class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int ptr_1 = m - 1;
        int ptr_2 = n - 1;
        int ptr_dest = nums1.size() - 1;
            
        while(ptr_1 >= 0 && ptr_2 >= 0) {
            if(nums1[ptr_1] > nums2[ptr_2]) {
                
                nums1[ptr_dest] = nums1[ptr_1];
                ptr_dest = ptr_dest - 1;
                ptr_1 = ptr_1 - 1;
                
            } else if (nums1[ptr_1] < nums2[ptr_2]) {
                
                nums1[ptr_dest] = nums2[ptr_2];
                ptr_dest = ptr_dest - 1;
                ptr_2 = ptr_2 - 1;                
                
            } else {
                
                nums1[ptr_dest] = nums2[ptr_2];
                ptr_dest = ptr_dest - 1;
                nums1[ptr_dest] = nums1[ptr_1];
                ptr_dest = ptr_dest - 1;
                ptr_1 = ptr_1  - 1;
                ptr_2 = ptr_2 - 1;          
                
            }
        }
        
        while(ptr_1 >= 0) {
 
            nums1[ptr_dest] = nums1[ptr_1];
            ptr_dest = ptr_dest - 1;
            ptr_1 = ptr_1 - 1;
            
        }
        
        while(ptr_2 >= 0) {
 
            nums1[ptr_dest] = nums2[ptr_2];
            ptr_dest = ptr_dest - 1;
            ptr_2 = ptr_2 - 1;
            
        }
        
    }
};
