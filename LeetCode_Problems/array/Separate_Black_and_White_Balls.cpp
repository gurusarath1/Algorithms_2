class Solution {
public:
    long long minimumSteps(string s) {

        bool start_counting_ones = false;
        long long num_flips = 0;
        long long num_zeroes = 0;
        for(int i=s.size() - 1; i>=0; i--) {
            if(s[i] == '0') {
                start_counting_ones = true;
                num_zeroes++;
            }

            if(start_counting_ones && s[i] == '1') {
                num_flips += num_zeroes;
            }
        }
        
        return num_flips;
    }
};
