class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int start = 0;
        int sum = 0;
        int result = 0;
        
        for(int end=0; end < arr.size(); end++) {
            
            if(end <= k-1) {
                sum += arr[end];
                
                if(end == k-1) {
                    if(sum/k >= threshold) result++;
                }
                
            } else {
                
                sum -= arr[start];
                start++;
                sum += arr[end];
                if(sum/k >= threshold) result++;
            }
        }
        
        return result;
    }
};
