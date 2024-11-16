class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {

        vector<int> res;
        deque<int> window;

        for(int i=0; i<nums.size(); i++) {

            if(window.empty()) {
                window.push_back(i);
            }

            else if(!window.empty() && window.size() < k) {
                if(nums[i] == (nums[i-1] + 1)) {
                    ;
                } else {
                    window.clear();
                }

                window.push_back(i);
            }

            else if(!window.empty() && window.size() == k) {
                if(nums[i] == (nums[i-1] + 1)) {
                    window.pop_front();
                } else {
                    window.clear();
                }

                window.push_back(i);
            }

            if(i >= k-1) {
                if(window.size() == k) {
                    res.push_back(nums[window.back()]);
                } else {
                    res.push_back(-1);
                }
            }

        }

        return res;
    }
};
