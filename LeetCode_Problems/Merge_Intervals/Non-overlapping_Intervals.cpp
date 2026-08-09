class Solution {
public:

    static bool compareEndTimes(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        // Sort based on increasing end time
        sort(intervals.begin(), intervals.end(), compareEndTimes);

        int current_end_time = INT_MIN;
        int num_removal = 0;

        for(vector<int> inter : intervals) {
            int start_time = inter[0];
            int end_time = inter[1];

            if(start_time >= current_end_time) {
                // No overlap - goto next interval's end
                current_end_time = end_time;
            } else {
                // This interval can be removed
                num_removal++; 
            }
        }

        return num_removal;
    }
};
