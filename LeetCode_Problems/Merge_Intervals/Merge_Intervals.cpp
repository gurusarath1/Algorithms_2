/*
Given an array of intervals where intervals[i] = [starti, endi],
merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/

class Solution {
public:

    static bool compareStartTimes(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> merged;

        // Start based on start times
        sort(intervals.begin(), intervals.end(), compareStartTimes);

        // Current window
        int curr_start = intervals[0][0];
        int curr_end = intervals[0][1];

        for(int i=1; i<intervals.size(); i++) {
            int start_i = intervals[i][0];
            int end_i = intervals[i][1];

            if(start_i > curr_end) {
                // No Overlap case = Start/Create new interval
                merged.push_back(vector<int>{curr_start, curr_end});
                curr_start = start_i;
                curr_end = end_i;
            } else {
                // Overlap case
                if(end_i > curr_end) { // If end time exceeds
                    curr_end = end_i; // Update end time
                } else {
                    ; // Interval i is fully inside the current running interval
                }
            }
        }

        // Push the last running interval
        merged.push_back(vector<int>{curr_start, curr_end});

        return merged;
    }
};
