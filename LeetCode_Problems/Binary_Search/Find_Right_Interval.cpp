class Solution {
public:

    static bool comp(vector<int> &a, vector<int> &b) {
        return a[0] <= b[0];
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {


        // Keep a memo of all interval indices
        map<vector<int>, int> index_memo;
        for(int i=0; i<intervals.size(); i++) {
            index_memo[intervals[i]] = i;
        }

        vector<int> ret_vals;
        ret_vals.resize(intervals.size());
        
        // Sort based on start time
        sort(intervals.begin(), intervals.end(), comp);

        for(int i=0; i<intervals.size(); i++) {
            int low = i; // not i+1 because form the problem - "Note that i may equal j"
            int high = intervals.size() - 1;

            // Do binary search
            int end_i = intervals[i][1];
            while(low <= high) {
                int mid = low + (high - low) / 2;
                int start_mid = intervals[mid][0];

                if(start_mid < end_i) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if(low < intervals.size()) {
                ret_vals[index_memo[intervals[i]]] = index_memo[intervals[low]];
            } else {
                ret_vals[index_memo[intervals[i]]] = -1;
            }

        }

        return ret_vals;
    }
};
