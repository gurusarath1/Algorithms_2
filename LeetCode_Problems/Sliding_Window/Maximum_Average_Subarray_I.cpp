class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double avg = 0;
        double sum = 0;
        int start = 0;
        double max_avg = -DBL_MAX;
        
        for(int i=0; i<nums.size(); i++) {
            
            sum += nums[i];
            
            if(i == k-1) {
                avg = sum / k;
                if(avg > max_avg) max_avg = avg;             
            }
            
            if(i >= k) {
                sum -= nums[start];
                avg = sum / k;
                if(avg > max_avg) max_avg = avg;
                start++;
            }
            
        }
        
        return max_avg;
        
    }
};
