class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        

        int p1 = 0;
        int p2 = 0;
        multiset<int> ms;
        int max_len = 0;

        for(p2=0; p2<nums.size(); p2++) {
            ms.insert(nums[p2]);
    
            while(*ms.rbegin() - *ms.begin() > limit) {
                ms.erase(ms.find(nums[p1])); // If you directly erase the number, It will earse all the numbers in the set.
                p1++;
            }

            if(max_len < (p2 - p1 + 1)) max_len = p2 - p1 + 1;
        }


        return max_len;

    }
};
