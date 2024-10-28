class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int max_num_in_arrya = nums[nums.size() - 1];

        int max_seq_len = -1;

        for(int i=0; i<nums.size(); i++) {

            int found_loc = i;
            int seq_len = 1;

            // Check if we can build the sequenct from nums[i]
            while(1) {
                long long square = (long long)nums[found_loc] * (long long)nums[found_loc]; // Sqare num to search

                if(square > max_num_in_arrya) return max_seq_len; // Cannot find seq from this num so return

                int low = found_loc + 1; // search from next number
                int high = nums.size() - 1; // till end of array
                bool found = false;
                while(low <= high) {
                    int mid = low + (high - low) / 2;

                    if(nums[mid] == square) {
                        found = true; // Square number found
                        found_loc = mid; // Next location to search from
                        seq_len++; // increase the length
                        if(seq_len >= 2 && seq_len > max_seq_len) max_seq_len = seq_len; // Only lens greater than 1 is considered as a sequence
                        break;
                    } else if(nums[mid] < square) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }

                if(!found) {
                    break; // Sequence ended. Goto next number in the array
                }
            }

        }

        return max_seq_len; // we wont reach this
        
    }
};
