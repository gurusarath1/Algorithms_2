class Solution {
public:

    vector<int> num_days_with_pass = {1,7,30};

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_map<int, int> min_costs;
        return get_min_cost(0, days, costs, min_costs);
    }

    int get_min_cost(int day_idx, vector<int>& days, vector<int>& costs, unordered_map<int,int>&min_costs) {

        if(day_idx >= days.size()) {
            return 0;
        }

        if(min_costs.find(day_idx) != min_costs.end()) {
            return min_costs[day_idx];
        }

        int min_cost = INT_MAX;

        for(int j=0; j<costs.size(); j++) {
            int last_valid_day_with_pass = num_days_with_pass[j] + days[day_idx] - 1;

            int low = day_idx+1;
            int high = days.size() - 1;

            while(high >= low) {
                int mid = low + (high - low) / 2;

                if(days[mid] <= last_valid_day_with_pass) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            int cost_if_i_take_this_pass = costs[j] + get_min_cost(low, days, costs, min_costs);

            min_cost = min(min_cost, cost_if_i_take_this_pass);
        }

        min_costs[day_idx] = min_cost;

        return min_cost;
    }
};
