class Solution {
public:

    bool is_possible(int n, int maxSum, int index, int val_at_index) {

        long long sum = 0;
        int current_val = val_at_index;
        for(int i=index; i<n; i++) {
            sum += current_val;

            if(sum > maxSum) return false;

            if(current_val > 1) {
                current_val--;
            } else {
                sum += n - 1 - i;
                if(sum > maxSum) return false;
                break;
            }
        }

        current_val = val_at_index - 1;
        for(int i=index-1; i>=0; i--) {

            sum += current_val;

            if(sum > maxSum) return false;

            if(current_val > 1) {
                current_val--;
            } else {
                sum += i;
                if(sum > maxSum) return false;
                break;
            }
        }

        return true;

    }

    int maxValue(int n, int index, int maxSum) {

        int low = 0;
        int high = 10000000000;
        int max_possible_val;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(is_possible(n, maxSum, index, mid)) {
                low = mid + 1;
                max_possible_val = mid;
            } else {
                high = mid - 1;
            }

        }
        
        return max_possible_val;

    }
};
