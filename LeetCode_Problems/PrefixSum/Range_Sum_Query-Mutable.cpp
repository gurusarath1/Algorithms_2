class NumArray {
public:
    vector<int> prefix_sum;
    NumArray(vector<int>& nums) {

        int sum = 0;
        for(int n : nums) {
            sum += n;
            prefix_sum.push_back(sum);
        }
    }
    
    void update(int index, int val) {
        int num_at_index = sumRange(index,index);

        for(int i=index; i<prefix_sum.size(); i++) {
            prefix_sum[i] = prefix_sum[i] - num_at_index + val;
        }
    }
    
    int sumRange(int left, int right) {
        if(left <= 0) return prefix_sum[right];
        return prefix_sum[right] - prefix_sum[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
