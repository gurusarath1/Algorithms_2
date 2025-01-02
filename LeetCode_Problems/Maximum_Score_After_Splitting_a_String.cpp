class Solution {
public:
    int maxScore(string s) {

        vector<int> num_zeros_ones_right(2, 0);

        for(char c : s) {
            if(c == '0') {
                num_zeros_ones_right['0' - '0'] += 1;
            } else {
                num_zeros_ones_right['1' - '0'] += 1;
            }
        }

        vector<int> num_zeros_ones_left(2, 0);
        int score = INT_MIN;
        int max_score = INT_MIN;
        for(char c : s) {
            if(c == '0') {
                num_zeros_ones_left['0' - '0'] += 1;
                num_zeros_ones_right['0' - '0'] -= 1;
            } else {
                num_zeros_ones_left['1' - '0'] += 1;
                num_zeros_ones_right['1' - '0'] -= 1;
            }

            if(num_zeros_ones_right[0] == 0 && num_zeros_ones_right[1] == 0) break;

            score = num_zeros_ones_left[0] + num_zeros_ones_right[1];
            max_score = max(score, max_score);
        }
        
        return max_score;
    }
};
