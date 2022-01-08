class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> pSum(nums.size());
        vector<int> sSum(nums.size());
        int ps = 0, ss = 0;
        
        int j;
        for(int i=0, j=nums.size()-1; i<nums.size(); i++, j--) {
            ps += nums[i];
            ss += nums[j];
            
            pSum[i] = ps;
            sSum[j] = ss;
        }
        
        for(int i=0; i<nums.size(); i++) {
            if(pSum[i] == sSum[i]) return i;
        }
        return -1;
    }
};
