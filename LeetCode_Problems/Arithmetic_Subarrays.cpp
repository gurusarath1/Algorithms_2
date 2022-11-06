class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {

        vector<bool> result;

        for(int i=0; i<l.size(); i++) {
            result.push_back( can_form_ap_array(nums, l[i], r[i]) );
        }        

        return result;
    }


    bool can_form_ap_array(vector<int> &nums, int start, int end) {

        // Size 1 or 2 arrays are always AP
        if(start ==  end || end == start + 1) return true;

        int min_val = nums[start];
        int max_val = nums[start];
        for(int i=start+1; i<=end; i++) {
            min_val = min(min_val, nums[i]);
            max_val = max(max_val, nums[i]);
        }

        // All values are equal in the array
        if(min_val == max_val) return true;

        int common_diff = (max_val - min_val) / (end - start);

        // common_diff = 0 then the array might look something like [1,1,2,2,2,2,2]
        // common_diff = 0 if (end - start) > (max_val - min_val)
        if(common_diff == 0) return false;

        if((max_val - min_val) % common_diff != 0) return false;

        vector<bool> is_present(end - start + 1, false);

        for(int i=start; i<=end; i++) {

            // Check if is element can be in the AP sequence
            if( ((nums[i] - min_val) % common_diff) != 0 ) return false;

            int value_expected_to_be_at_index = (nums[i] - min_val) / common_diff;

            // Check if this value can be in AP of given size
            if(value_expected_to_be_at_index >= is_present.size()) return false;

            // Check if Duplicate value found
            if(is_present[value_expected_to_be_at_index]) return false;

            is_present[value_expected_to_be_at_index] = true;
        }

        return true;

    }
};
