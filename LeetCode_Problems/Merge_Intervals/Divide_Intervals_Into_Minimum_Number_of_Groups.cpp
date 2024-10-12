class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        priority_queue<int> pq;

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });

        int groups = 0;
        for(int i=0; i<intervals.size(); i++) {

            int start_time = intervals[i][0];
            int end_time = intervals[i][1];

            while(!pq.empty() && (-pq.top()) < start_time) {
                pq.pop();
            }

            pq.push(-end_time);
            if(pq.size() > groups) groups = pq.size();
        }
        
        return groups;
    }
};
