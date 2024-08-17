class Solution {
public:

    int get_sum(vector<int> &nums, int divisor) {

        int sum = 0;

        for(int num : nums) {
            sum += ceil((double)num / (double)divisor);
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        int low = 1;
        int high = INT_MAX;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            int sum = get_sum(nums, mid);

            if(sum > threshold) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }

        }

        return low;
        
    }
};
