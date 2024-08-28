class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int first_smallest = INT_MAX;
        int second_smallest = INT_MAX;
        for(int n : nums) {

            if(first_smallest >= n) {
                first_smallest = n;
            } else if(second_smallest >= n) {
                second_smallest = n;
            } else {
                return true;
            }

        }

        return false;
    }
};
