class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> prefixSum(n+1,0);
        
        for(vector<int> booking : bookings) {
            int first = booking[0];
            int last = booking[1];
            int seats = booking[2];
            
            prefixSum[first - 1] += seats;
            prefixSum[last] -= seats;
            
        }
        
        int sum = 0;
        for(int i=0; i<prefixSum.size(); i++) {
            sum += prefixSum[i];
            prefixSum[i] = sum;
        }
        
        prefixSum.resize(prefixSum.size() - 1);
        
        return prefixSum;
    }
};
