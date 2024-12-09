class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> res;

        bool prev_is_odd = nums[0] & 1;
        int current_good_set_index = 0;
        vector<int> good_sets(nums.size(), 0);

        for(int i=1; i<nums.size(); i++) {

            bool current_is_odd = (nums[i] & 1);

            if(current_is_odd == prev_is_odd) current_good_set_index++;
            
            good_sets[i] = current_good_set_index;

            prev_is_odd = current_is_odd;
        }

        for(auto q : queries) {
            res.push_back(good_sets[q[0]] == good_sets[q[1]]);
        }

        return res;
    }
};
