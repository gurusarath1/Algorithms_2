class Solution {
public:
    int largestCombination(vector<int>& candidates) {

        int max_count = 0;
        for(int set_bit=0; set_bit<31; set_bit++) {

            unsigned int mask = 1 << set_bit;
            int count = 0;
            for(int num : candidates) {
                if(mask & num) {
                    count++;
                    if(count > max_count) max_count = count;
                }
            }

        }

        return max_count;
    }
};
