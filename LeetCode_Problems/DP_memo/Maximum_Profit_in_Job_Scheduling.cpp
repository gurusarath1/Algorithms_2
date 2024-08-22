class Solution {
public:

    static bool sort_key(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        vector<vector<int>> jobs;

        for(int i=0; i<profit.size(); i++) {
            jobs.push_back( vector<int>{startTime[i], endTime[i], profit[i]} );
        }

        sort(jobs.begin(), jobs.end(), sort_key);
        map<int,int> memo;

        return max_profit(jobs, 0, 0, memo);
    }

    int bin_search(vector<vector<int>> &jobs, int end_time, int low, int high) {

        int last_index = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(jobs[mid][0] >= end_time) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if(low == last_index+1) return -1;

        return low;
    }

    int max_profit(vector<vector<int>> &jobs, int current_index, int prev_end_time, map<int,int> &memo) {

        if(current_index >= jobs.size()) return 0;

        if(memo.find(current_index) != memo.end()) {
            return memo[current_index];
        }

        int current_start_time = jobs[current_index][0];
        int profit_if_job_included = 0;
        if(prev_end_time <= current_start_time) {
            // Can include the job
            int profit_from_this_job = jobs[current_index][2];
            int current_end_time = jobs[current_index][1];

            int next_doable_job_index = bin_search(jobs, current_end_time, current_index+1, jobs.size()-1);

            if(next_doable_job_index == -1) {
                profit_if_job_included = profit_from_this_job;
            } else {
                int next_job_sub_tree_profit = max_profit(jobs, next_doable_job_index, current_end_time, memo);
                profit_if_job_included = next_job_sub_tree_profit + profit_from_this_job;
            }
            
        }

        // Current Job not included
        int profit_if_job_not_included = max_profit(jobs, current_index+1, prev_end_time, memo);

        // Memo
        memo[current_index] = max(profit_if_job_included, profit_if_job_not_included);

        return memo[current_index];
    }
};
