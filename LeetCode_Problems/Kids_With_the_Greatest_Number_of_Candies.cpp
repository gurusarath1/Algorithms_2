class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

        int max_candy = INT_MIN;
        vector<bool> ret(candies.size(), false);

        for(int c : candies) {
            if(c > max_candy) max_candy = c;
        }

        for(int i=0; i<candies.size(); i++) {
            if(candies[i] + extraCandies >= max_candy) {
                ret[i] = true;
            }
        }

        return ret;

    }
};
