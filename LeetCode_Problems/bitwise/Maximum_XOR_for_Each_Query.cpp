class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {

        int xor_of_nums = 0;
        int max_possible_k = (1 << maximumBit) - 1; // bitmask
        vector<int> ks;
        for(int n : nums) {
            xor_of_nums = xor_of_nums ^ n;
            int k = (xor_of_nums ^ max_possible_k) & max_possible_k;
            ks.push_back(k);
        }
        
        reverse(ks.begin(), ks.end());

        return ks;
    }
};
