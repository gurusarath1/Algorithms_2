class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<int> prefixSum;
        
        for(vector<int> trip : trips) {
            
            int numPas = trip[0];
            int from = trip[1];
            int to = trip[2];
            
            if(to+1 > prefixSum.size()) {
                prefixSum.resize(to+1, 0);
            }
            
            prefixSum[from] += numPas;
            prefixSum[to] -= numPas;
        }
        
        int sum = 0;
        for(int i=0; i<prefixSum.size(); i++) {
            sum += prefixSum[i];
            prefixSum[i] = sum;
            
            if(sum > capacity) return false;
        }
        
        return true;
    }
};
