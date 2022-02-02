class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        
        vector<int> prefixSum(arr.size(), 0);
        int sum = 0;
        for(int i=0; i<arr.size(); i++) {
            sum += arr[i];
            prefixSum[i] += sum;
        }
        
        int ans = 0;
        // Generate all odd lengths
        for(int i=0; i<arr.size(); i++) {
            
            for(int j=i; j<arr.size(); j+=2) {
                ans += prefixSum[j] - prefixSum[i] + arr[i];
            }
            
        }
        
        return ans;
    }
};
