class Solution {
public:
    map<vector<int>, int> memo;
    int superEggDrop(int k, int n) {
        return dp(k, n);
    }

    int dp(int num_eggs, int num_floors) {

        vector<int> memo_key;
        memo_key.push_back(num_eggs);
        memo_key.push_back(num_floors);

        if(memo.find(memo_key) != memo.end()) {
            return memo[memo_key];
        }

        if(num_eggs <= 0 || num_floors <= 0) {
            return 0;
        }

        if(num_eggs == 1 || num_floors == 1) {
            return num_floors;
        }

        int low = 1;
        int high = num_floors;
        int min_trials = INT_MAX;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            int case_1_min = dp(num_eggs-1, mid-1); // Egg Breaks
            int case_2_min = dp(num_eggs, num_floors - mid); // Egg Does not Break

            if(case_1_min == case_2_min) {
                min_trials = 1 + case_1_min;
                break;
            }

            if(case_2_min > case_1_min) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }

        }

        if(min_trials == INT_MAX) {

            int case_1_min_with_low = dp(num_eggs-1, low-1); // Egg Breaks
            int case_2_min_with_low = dp(num_eggs, num_floors - low); // Egg Does not Break

            int case_1_min_with_high = dp(num_eggs-1, high-1); // Egg Breaks
            int case_2_min_with_high = dp(num_eggs, num_floors - high); // Egg Does not Break

            
            min_trials = 1 + min( max(case_1_min_with_low, case_2_min_with_low) , max(case_1_min_with_high, case_2_min_with_high) );
        }

        memo[memo_key] = min_trials;

        return min_trials;
    }

};
