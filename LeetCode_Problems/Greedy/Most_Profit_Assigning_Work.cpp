class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

        vector<pair<int,int>> sorted_profit_difficulty;

        for(int i=0; i<profit.size(); i++) {
            sorted_profit_difficulty.push_back({-profit[i], -difficulty[i]});
        }

        sort(sorted_profit_difficulty.begin(), sorted_profit_difficulty.end());
        sort(worker.begin(), worker.end());

        int total_profit = 0;
        for(int i=0; i<worker.size(); i++) {

            for(int j=0; j<sorted_profit_difficulty.size(); j++) {
                int profit = -sorted_profit_difficulty[j].first;
                int diffi = -sorted_profit_difficulty[j].second;
                if(worker[i] >= diffi) {
                    total_profit += profit;
                    break;
                }
            }

        }

        return total_profit;
        
    }
};
