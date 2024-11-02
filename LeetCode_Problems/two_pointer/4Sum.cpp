class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        if(nums.size() < 4) return vector<vector<int>>();

        sort(nums.begin(), nums.end());

        vector<vector<int>> ret;

        set<vector<int>> memo;

        for(int i=0; i<nums.size()-3; i++) {
            for(int j=i+1; j<nums.size()-2; j++) {
                auto ret_ = twoSum(nums, j+1, nums.size()-1, (long long)target - (long long)nums[i] - (long long)nums[j]);

                if(ret_.size()) {

                    for(vector<int> &two_sum : ret_) {
                        two_sum.push_back(nums[i]);
                        two_sum.push_back(nums[j]);
                        sort(two_sum.begin(), two_sum.end());
                        if(memo.find(two_sum) == memo.end()) {
                            ret.push_back(two_sum);
                            memo.insert(two_sum);
                        }
                    }

                }

            }
        }

        return ret;
    }

    vector<vector<int>> twoSum(vector<int>& nums, int ptr1, int ptr2, long long target) {

        vector<vector<int>> res;

        while(ptr2 > ptr1) {
            if((long long)nums[ptr1] + (long long)nums[ptr2] == target) {
                res.push_back( vector<int>{nums[ptr1], nums[ptr2]} );
                ptr1++;
                ptr2--;
            } else if((long long)nums[ptr1] + (long long)nums[ptr2] > target) {
                ptr2--;
            } else {
                ptr1++;
            }
        }

        return res;
    }
};
