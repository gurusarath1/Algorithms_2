/*
There are several cards arranged in a row, and each card has an associated number of points.
The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row.
You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int max_points = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int win_len = cardPoints.size() - k;

        int sum = 0;
        int min_sum = INT_MAX;
        for(int i=0; i<cardPoints.size(); i++) {
            sum += cardPoints[i];
            if(i < win_len) {
                min_sum = sum;
            } else {
                sum -= cardPoints[i - win_len];
                if(min_sum > sum) {
                    min_sum = sum;
                }
            }
        }

        return max_points - min_sum;
    }
};

