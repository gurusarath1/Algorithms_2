class Solution {
public:
    int countOdds(int low, int high) {
        int num_nums = high - low + 1;
        if(num_nums%2 == 0) { // Equal number of odd and even numbers
            return num_nums/2;
        } else {
            if(low%2 == 0) {
                return num_nums/2;
            } else {
                return num_nums/2 + 1;
            }
        }
    }
};
