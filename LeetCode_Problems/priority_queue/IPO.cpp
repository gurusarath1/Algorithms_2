class Solution {
public:

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        vector<pair<int,int>> sorted_vec_based_on_capital;

        for(int i=0; i<profits.size(); i++) {
            sorted_vec_based_on_capital.emplace_back( capital[i], profits[i] );
        }

        // sort based on decreasing affordability (or increasing required capital)
        sort(sorted_vec_based_on_capital.begin(), sorted_vec_based_on_capital.end());

        int idx = 0; // index of the project that we are current looking at
        int current_capital = w;
        priority_queue<int> profits_priority_queue;
        for(int i=0; i<k; i++) {

            // Add all projects that can be completed with current capital
            while(idx < profits.size() && current_capital >= sorted_vec_based_on_capital[idx].first) {
                int profit_from_this_project = sorted_vec_based_on_capital[idx].second;
                profits_priority_queue.push(profit_from_this_project);
                idx++;
            }

            // if(cant afford any more project) return the current capital gained
            if(profits_priority_queue.empty()) return current_capital;

            // Do a project and get the profit
            int max_profit_from_current_set_of_possible_projects = profits_priority_queue.top(); // We pick the project which gives the most profit
            current_capital += max_profit_from_current_set_of_possible_projects; // Update the capital

            // Profit utilized. Remove the profit from queue
            profits_priority_queue.pop();

            // Since our capital has increased, we might be able to afford new projects that we couldn't afford before.
            // Go back up to the while loop and add the profits of all projects that we can afford.
        }

        return current_capital;
    }
};
