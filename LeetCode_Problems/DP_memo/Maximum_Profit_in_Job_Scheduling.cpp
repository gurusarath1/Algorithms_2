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

    int max_profit(vector<vector<int>> &jobs, int current_index, int prev_end_time, map<int,int> &memo) {

        if(current_index >= jobs.size()) return 0;

        int current_start_time = jobs[current_index][0];
        int profit_if_job_included = 0;
        if(prev_end_time <= current_start_time) {
            // Can include the job

            if(memo.find(current_index) != memo.end()) {
                //cout << "Memo Hit";
                return memo[current_index];
            }


            int profit_from_this_job = jobs[current_index][2];
            int current_end_time = jobs[current_index][1];
            int next_job_sub_tree_profit = max_profit(jobs, current_index+1, current_end_time, memo);
            profit_if_job_included = next_job_sub_tree_profit + profit_from_this_job;
            
        }

        // Current Job not included
        int profit_if_job_not_included = max_profit(jobs, current_index+1, prev_end_time, memo);

        if(prev_end_time <= current_start_time) {
            memo[current_index] = max(profit_if_job_included, profit_if_job_not_included);
        }

        return max(profit_if_job_included, profit_if_job_not_included);
    }
};
