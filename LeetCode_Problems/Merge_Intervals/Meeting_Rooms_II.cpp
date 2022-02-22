class Solution {
public:
    
    static bool compare(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), compare);
        
        vector<int> current_interval = intervals[0];
        int num_classes = 1;
        int max_num_classes = 1;
        for(int i=1; i<intervals.size(); i++) {
            
            if(intervals[i][0] >= current_interval[1]) {
                // Non overlapping intervals
                current_interval[0] = intervals[i][0];
                current_interval[1] = intervals[i][1];
                num_classes = 1;
            } else {
                // Overlapping intervals
                if(intervals[i][1] < current_interval[1]) {
                    // interval is completely inside
                    num_classes++;
                    if(max_num_classes < num_classes) max_num_classes = num_classes;
                } else {
                    // overlapping intervals (partially out)
                    current_interval[1] = intervals[i][1];
                    num_classes++;
                    if(max_num_classes < num_classes) max_num_classes = num_classes;                   
                }
                
            }
        }
        
        return max_num_classes;
        
    }
};
