class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int,int>> nums_with_idx;
        for(int i=0; i<nums.size(); i++) {
            nums_with_idx.push_back(pair<int,int>{nums[i], i});
        }

        sort(nums_with_idx.begin(), nums_with_idx.end());

        int p1 = 0, p2 = nums.size() - 1;
        while(p1 < p2) {
            if(nums_with_idx[p1].first + nums_with_idx[p2].first == target) {
                return vector<int>{nums_with_idx[p1].second, nums_with_idx[p2].second};
            } else if (nums_with_idx[p1].first + nums_with_idx[p2].first > target) {
                p2--;
            } else {
                p1++;
            }
        }

        return vector<int>{};
        
    }
};
