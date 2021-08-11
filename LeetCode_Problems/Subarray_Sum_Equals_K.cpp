class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int count = 0;
        
        for(int i=0; i<nums.size(); i++) {
            
            for(int j=i+1; j<=nums.size(); j++) {
                
                int sum = 0;
                for(int k=i; k<j; k++) {
                    sum += nums[k];
                }
                
                if(sum == k) count++;
            }
        }
        
        return count;
        
        
    }
};


/* 	Time Limit Exceeded */
