class Solution {
public:
    long long minEnd(int n, int x) {

        long long first_num = x; // x will always be the first num

        // Merge n-1 and first_num to get last num
        long long merge_last_num = n - 1;
        long long last_num = x;

        int bit_pos = 0;
        int insert_index = 0;
        while(merge_last_num) {
            long long bit_to_insert  = merge_last_num & 1; // get the bit to merge
            merge_last_num = merge_last_num >> 1;

            // find merge position in last num
            while( (((long long)1 << insert_index) & last_num) ) {
                insert_index++;
            }

            last_num |= (bit_to_insert << insert_index); //merge
            insert_index++;
        }

        return last_num;
    }
};
