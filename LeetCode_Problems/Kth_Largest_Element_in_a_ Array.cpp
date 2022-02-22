class Solution {
public:
    
    int partition(int start, int end, vector<int> &nums) {
        
        if(start == end) {
            return start;
        }
        
        int i = start;
        int j = end;
        
        while(i < j) {
            do {
                i++;
            } while(nums[i] > nums[start]);
            
            do {
                j--;
            } while(nums[j] < nums[start]);
            
            if(i < j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        
        int temp = nums[j];
        nums[j] = nums[start];
        nums[start] = temp;
        
        return j;
    }
    
    
    int get_kth_largest(int start, int end, vector<int> &nums, int k) {
        
        int pivot_index = partition(start, end, nums);
        
        if(pivot_index == k- 1) {
            return nums[pivot_index];
        } else if(pivot_index < k-1) {
            return get_kth_largest(pivot_index+1, end, nums, k);
        } else {
            return get_kth_largest(start, pivot_index, nums, k);
        }
    }
    
    
    int findKthLargest(vector<int>& nums, int k) {
        
        nums.push_back(INT_MIN);
        
        return get_kth_largest(0, nums.size() - 1, nums,k);
        
    }
};
