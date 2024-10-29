class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        } );

        int last_end_time = -1;
        for(vector<int> &i : intervals) {
            if(i[0] < last_end_time) {
                return false;
            } else {
                last_end_time = i[1];
            }
        }
        
        return true;
    }
};
