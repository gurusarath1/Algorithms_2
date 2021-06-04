class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int> squared_sorted;
        
        int pointer1 = 0;
        int pointer2;
        
        while(pointer1 < nums.size() && nums[pointer1] < 0) {
            pointer1++;
        }
        
        pointer2 = pointer1 - 1;
        
        while(pointer1 < nums.size() && pointer2 >= 0) {
            
            if(nums[pointer1]*nums[pointer1] < nums[pointer2]*nums[pointer2]) {
                
                squared_sorted.push_back(nums[pointer1] * nums[pointer1]);
                pointer1++;
                
            } else if(nums[pointer1]*nums[pointer1] > nums[pointer2]*nums[pointer2]) {
                
                squared_sorted.push_back(nums[pointer2] * nums[pointer2]);
                pointer2--;
                
            } else {
                squared_sorted.push_back(nums[pointer2] * nums[pointer2]);
                squared_sorted.push_back(nums[pointer2] * nums[pointer2]);
                pointer1++;
                pointer2--;
            }
        }
        
        while(pointer1 < nums.size()) {
            
            squared_sorted.push_back(nums[pointer1] * nums[pointer1]);
            pointer1++;
        }

        while(pointer2 >= 0) {
            
            squared_sorted.push_back(nums[pointer2] * nums[pointer2]);
            pointer2--;
        }
        
        return squared_sorted;
        
    }
};
