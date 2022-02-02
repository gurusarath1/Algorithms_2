class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        vector<int> prefixSum(cardPoints.size(), 0);
        
        int sum = 0;
        for(int i=0; i<cardPoints.size(); i++) {
            sum += cardPoints[i];
            prefixSum[i] = sum;
        }
        
        int compliment_size = cardPoints.size() - k;
        int smallest_sum = INT_MAX;
        // Check all sub arrays of compliment size
        for(int i=0 ; i<cardPoints.size(); i++) {
            
            int j = i + compliment_size - 1;
            if( j < cardPoints.size()) {
                if(prefixSum[j] - prefixSum[i] + cardPoints[i] < smallest_sum) smallest_sum = prefixSum[j] - prefixSum[i] + cardPoints[i];
            }
        }
        
        return sum - smallest_sum;
        
    }
};
