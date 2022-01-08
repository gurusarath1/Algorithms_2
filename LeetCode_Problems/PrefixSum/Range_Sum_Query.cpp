class NumArray {
public:
    vector<int> prefixSum;
    
    NumArray(vector<int>& nums) {
        int sum = 0;
        prefixSum.push_back(0);
        for(int num : nums) {
            sum += num;
            prefixSum.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right+1] - prefixSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
