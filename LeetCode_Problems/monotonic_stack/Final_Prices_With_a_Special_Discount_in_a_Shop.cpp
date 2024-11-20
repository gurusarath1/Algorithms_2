class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        stack<int> stk;
        vector<int> res(prices.size());
        res[prices.size() - 1] = prices[prices.size() - 1];
        stk.push(prices[prices.size() - 1]);

        for(int i=prices.size()-2; i>=0; i--) {
            while(!stk.empty() && stk.top() > prices[i]) {
                stk.pop(); // pop all values that are greater than me
            }

            if(stk.empty()) {
                res[i] = prices[i]; // no value greate than me
            } else {
                res[i] = prices[i] - stk.top();
            }

            stk.push(prices[i]);
        }

        return res;
    }
};
