class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

        int num2_size_multiplier = nums2.size() & 1 == 1 ? 1 : 2;
        int num1_size_multiplier = nums1.size() & 1 == 1 ? 1 : 2;
        int xors = 0;
        for(int n : nums1) {
            if(num2_size_multiplier == 1) { // Number of times this number will repeat (only even or odd matters)
                xors ^= n; // If the number repeats odd number of times it will not become zero
            }
        }
        for(int n : nums2) {
            if(num1_size_multiplier == 1) {
                xors ^= n;
            }
        }

        return xors;
    }
};
