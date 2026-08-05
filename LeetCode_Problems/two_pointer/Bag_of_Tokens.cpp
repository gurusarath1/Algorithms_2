class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {

        int l=0, r=tokens.size() - 1;
        int score = 0;
        int max_score = 0;
        sort(tokens.begin(), tokens.end());

        while(l <= r) {
            if(tokens[l] <= power) {
                power -= tokens[l];
                score++;
                if(max_score < score) max_score = score;
                l++;
            } else if (score >= 1) {
                power += tokens[r];
                score--;
                r--;
            } else {
                break; // No moves left
            }
        }
        
        return max_score;
    }
};
