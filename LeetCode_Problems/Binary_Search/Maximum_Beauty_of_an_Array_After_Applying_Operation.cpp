class Solution {
public:

    int max_sub_array = 1;

    int maximumBeauty(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        int best_sub_array_len = 1;

        for(int i=0; i<nums.size()-1; i++) {

            if(nums.size() - i <= best_sub_array_len) break;

            int low = i+1;
            int high = nums.size() - 1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                if(nums[mid] - nums[i] <= 2*k) {
                    best_sub_array_len = max(best_sub_array_len, mid - i + 1);
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

        }

        return best_sub_array_len;        
    }

};
