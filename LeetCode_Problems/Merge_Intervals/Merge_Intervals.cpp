class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), intervalCompare);
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> result;
        
        for(int i=1; i<intervals.size(); i++) {
            
            if(intervals[i][0] <= end) {
                
                if(end < intervals[i][1]) end = intervals[i][1];
            } else {
                
                result.push_back( vector<int>{start, end} );
                start = intervals[i][0];
                end = intervals[i][1];
            }
            
        }
        result.push_back( vector<int>{start, end} );
        return result;
        
    }
    
    static bool intervalCompare(vector<int> x, vector<int> y) {
        return x[0] < y[0];
    }
};
