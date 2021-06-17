class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        int maxUnits = 0;
        sort(boxTypes.begin(), boxTypes.end(), compare_unitsDesceding);
        
        for(int i=0; i<boxTypes.size(); i++) {
            
            if(boxTypes[i][0] <= truckSize) {
                truckSize -= boxTypes[i][0];
                maxUnits += boxTypes[i][0] * boxTypes[i][1];
            } else {
                maxUnits += truckSize * boxTypes[i][1];
                truckSize = 0;
            }
            
            if(truckSize == 0) break;
            
        }
        
        return maxUnits;
        
    }
    
    static bool compare_unitsDesceding(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};
