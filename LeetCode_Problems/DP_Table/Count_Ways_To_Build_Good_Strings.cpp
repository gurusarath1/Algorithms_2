class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {

        vector<int> dp(high+1);
        dp[0] = 1;

        int num_good_strings_in_range = 0;
        for(int string_size=1; string_size<=high; string_size++) {

            if(string_size-zero >= 0) {
                dp[string_size] += dp[string_size - zero];
                dp[string_size] %= 1000000007;
            }
            if(string_size-one >= 0) {
                dp[string_size] += dp[string_size - one];
                dp[string_size] %= 1000000007;
            }

            if(string_size >= low && string_size <= high) {
                num_good_strings_in_range += dp[string_size];
                num_good_strings_in_range %= 1000000007;
            }
        }
        
        return num_good_strings_in_range;
    }
};
