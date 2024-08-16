class Solution {
public:

    int num_days_to_load_all(vector<int>& weights, int ship_capacity) {

        int num_days = 0;

        // This loop will not terminate if the ship capacity is less than the max element in weights
        for(int i=0; i<weights.size();) {

            int current_load = 0;
            while(i<weights.size() && (current_load + weights[i]) <= ship_capacity) {
                current_load += weights[i];
                i++;
            }

            num_days++;
        }

        return num_days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = INT_MAX;

        while(low <= high) {

            int mid = low + (high - low) / 2;
            int nums_days_to_load = num_days_to_load_all(weights, mid);

            if(nums_days_to_load > days) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }

        }

        return low;
    }
};
