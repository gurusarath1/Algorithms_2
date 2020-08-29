//Best Time to Buy and Sell Stock II
/*
Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profits = 0;
        
        for(unsigned int i=1; i < prices.size(); i++)
        {
            if(prices[i] > prices[i-1])
            {
                profits += (prices[i] - prices[i-1]);
            }
        }
        return profits;
    }
};
