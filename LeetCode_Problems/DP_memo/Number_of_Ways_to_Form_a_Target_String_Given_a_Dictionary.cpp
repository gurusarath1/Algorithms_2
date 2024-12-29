class Solution {
public:
    int numWays(vector<string>& words, string target) {
        vector<vector<int>> memo(target.size(), vector<int>(words[0].size(), -1)); // (Current index in target, current column in words)

        return num_ways_support(words, target, target.size(), 0, memo);
    }


    int num_ways_support(vector<string>& words, string& target, int num_chars_to_match_in_target, int current_col_in_words, vector<vector<int>> &memo) {

        // Sub Problem Nature --
        // (Current index in target, current column in words)

        // Matched all letters ?
        if(num_chars_to_match_in_target == 0) {
            return 1;
        }

        // reached end without matching all?
        if(current_col_in_words >= words[0].size()) {
            return 0;
        }

        // Not enough chars left
        if(num_chars_to_match_in_target > words[0].size() - current_col_in_words) {
            return 0;
        }

        int target_index = target.size() - num_chars_to_match_in_target;

        // Already completed sub problem ?
        if(memo[target_index][current_col_in_words] != -1) {
            return memo[target_index][current_col_in_words];
        }


        long long total_num_ways = 0;
        for(int i=0; i<words.size(); i++) {
            if(words[i][current_col_in_words] == target[target_index]) {
                // Include this char form the current col
                total_num_ways += (num_ways_support(words, target, num_chars_to_match_in_target-1, current_col_in_words+1, memo) % 1000000007);
            }
        }

        // Don't include any char from current col
        total_num_ways += (num_ways_support(words, target, num_chars_to_match_in_target, current_col_in_words+1, memo) % 1000000007);

        // Memo the result of this sub problem
        memo[target_index][current_col_in_words] = total_num_ways % 1000000007;

        return memo[target_index][current_col_in_words];
    }

};
