class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {

        // Solution space search range
        int low=1;
        int high=0;
        for(int n : nums) {
            if(high < n) high = n;
        }

        int min_penality = high;
        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(is_possible(mid, nums, maxOperations)) {
                min_penality = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }

        }

        return min_penality;
    }

    bool is_possible(int penalty, vector<int>&bags, int max_splits_ops) {

        int total_split_ops = 0;
        for(int balls : bags) {
            if(balls <= penalty) continue;
            int num_split_ops_required = ceil(balls / (double)penalty) - 1;
            total_split_ops += num_split_ops_required;
            if(total_split_ops > max_splits_ops) return false;
        }

        return true;
    }

};
