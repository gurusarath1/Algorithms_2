class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int lowest_price = prices[0];
        int best_profit = 0;
        for(int i=1; i<prices.size(); i++) {

            int current_profit = prices[i] - lowest_price;
            if(current_profit > best_profit) {
                best_profit = current_profit;
            } else if (prices[i] < lowest_price) {
                lowest_price = prices[i];
            }
        }

        return best_profit;
    }
};
