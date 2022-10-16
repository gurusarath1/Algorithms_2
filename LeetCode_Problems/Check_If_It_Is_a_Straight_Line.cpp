class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        double slp;
        
        if( (coordinates[0][0] - coordinates[1][0]) == 0) {
            slp = DBL_MAX;
        } else {
            slp = (double)(coordinates[0][1] - coordinates[1][1]) / (double)(coordinates[0][0] - coordinates[1][0]);
        }
        
        vector<int> prev_point = coordinates[1];

        for(int i=2; i<coordinates.size(); i++) {
            double new_slp;
            
            if( (prev_point[0] - coordinates[i][0]) == 0 ) {
                new_slp = DBL_MAX;
            } else {
                new_slp = (double)(prev_point[1] - coordinates[i][1]) / (double)(prev_point[0] - coordinates[i][0]);
            }
            
            if(new_slp != slp) return false;
            
            prev_point = coordinates[i];
        }
        
        return true;
    }
};
