class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int start = -1;
        int end = -1;
        
        int left = 0;
        int right = nums.size()-1;
        
        while(left <= right) {
            
            int mid = left + (right - left) / 2;
            
            if(mid > 0 && nums[mid] == target && nums[mid - 1] != target) {
                start = mid;
                break;
            } else if ( mid == 0 && nums[mid] == target) {
                start = mid;
                break;
            }
            
            if(nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            
        }
        
        left = 0;
        right = nums.size() - 1;
        while(left <= right) {
            
            int mid = left + (right - left) / 2;
            
            if(mid < nums.size() - 1 && nums[mid] == target && nums[mid + 1] != target) {
                end = mid;
                break;
            } else if ( mid == nums.size() - 1 && nums[mid] == target) {
                end = mid;
                break;
            }
            
            if(nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            
        }
        
        
        return {start, end};
    }
};
