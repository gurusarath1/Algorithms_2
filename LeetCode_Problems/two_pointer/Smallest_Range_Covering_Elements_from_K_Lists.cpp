class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        vector<vector<int>> merged_list;

        for(int i=0; i<nums.size(); i++) {
            for(int j=0; j<nums[i].size(); j++) {
                merged_list.push_back(vector<int>{nums[i][j], i});
            }
        }

        sort(merged_list.begin(), merged_list.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        } );

        vector<int> num_elements_from(nums.size(), 0);

        int left = 0;
        int right = 0;
        num_elements_from[merged_list[right][1]] += 1;
        vector<int> ret_range(2, 0);
        int best_window_size = INT_MAX;

        while(right < merged_list.size() && left <= right) {

            bool is_valid_range = true;
            for(int i=0; i<num_elements_from.size(); i++) {
                if(num_elements_from[i] == 0) {
                    is_valid_range = false;
                    break;
                }
            }

            if(is_valid_range) {

                int window_size = merged_list[right][0] - merged_list[left][0];
                if(best_window_size > window_size) {
                    best_window_size = window_size;
                    ret_range[0] = merged_list[left][0];
                    ret_range[1] = merged_list[right][0];
                }
                num_elements_from[ merged_list[left][1] ] -= 1;
                left++;
            } else {
                right++;
                if(right >= merged_list.size()) break;
                num_elements_from[ merged_list[right][1] ] += 1;
            }
        }


        return ret_range;
        
    }
};
