class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int MinSum = INT_MAX;
        int MinDiff = INT_MAX;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size() - 2; i++) {
            
            int low = i + 1;
            int high = nums.size() - 1;
            
            while(low < high) {
                if(nums[i] + nums[low] + nums[high] > target) {
                    
                    if(nums[i] + nums[low] + nums[high] - target < MinDiff) {
                        MinDiff = nums[i] + nums[low] + nums[high] - target;
                        MinSum = nums[i] + nums[low] + nums[high];
                    }
                        
                        
                    high--;
                    
                } else if (nums[i] + nums[low] + nums[high] < target) {
                    
                    if(target - nums[i] - nums[low] - nums[high] < MinDiff) {
                        MinDiff = target - nums[i] - nums[low] - nums[high];
                        MinSum = nums[i] + nums[low] + nums[high];
                    }
                    
                    low++;
                } else {
                    return target;
                }
            }
            
        }
        
        return MinSum;
        
    }
};
