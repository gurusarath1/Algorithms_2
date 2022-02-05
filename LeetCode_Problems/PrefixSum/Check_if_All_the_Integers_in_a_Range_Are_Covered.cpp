class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        
        vector<int> prefixSum(right+1, 0);
        
        for(vector<int> range : ranges) {
            int start = range[0];
            int end = range[1];
            
            if(end + 1 > prefixSum.size()) {
                prefixSum.resize(end + 1, 0);
            }
            
            prefixSum[start - 1] += 1;
            prefixSum[end] -= 1;
        }
        
        int sum = 0;
        for(int i=0; i<prefixSum.size(); i++) {
            sum += prefixSum[i];
            prefixSum[i] = sum;
        }
        
        for(int i=left-1; i<=right-1; i++) {
            if(prefixSum[i] == 0) return false;
        }
        
        return true;
    }
};
