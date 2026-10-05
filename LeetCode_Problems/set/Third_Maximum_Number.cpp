/*
You are given an integer array nums.

Return the third distinct maximum number in this array.
If the third maximum does not exist, return the maximum number.
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {

        set<long long> st;

        for(long long n : nums) {
            st.insert(-n);
        }

        int third_max = -(*st.begin());
        for(int i=0; i<3; i++) {
            if(st.empty()) break;
            if(i != 2) {
                st.erase(st.begin());
            } else {
                return -(*st.begin());
            }
        }
        
        return third_max;
    }
};
