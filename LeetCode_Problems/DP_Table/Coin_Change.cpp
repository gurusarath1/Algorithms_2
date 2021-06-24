class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount + 1, -1);
        int min_coins;
        dp[0] = 0;
        for(int i=1; i<=amount; i++) {
            
            min_coins = INT_MAX;
            for(int coin : coins) {
                if(i - coin >= 0 && dp[i - coin] >= 0) {
                    min_coins = min( dp[i - coin] + 1, min_coins);
                }
            }
            
            if(min_coins == INT_MAX) {
                dp[i] = -1;
            } else {
                dp[i] = min_coins;
            }
            
        }

        return dp[amount];
        
    }
};
