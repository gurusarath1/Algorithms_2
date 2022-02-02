class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        map<int,int> sum_index;
        sum_index[0] = -1;
        int sum =0;
        int longest_sub_array = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += (nums[i] == 0 ? -1 : 1);
            
            if(sum_index.find(sum) != sum_index.end()) {
                if(i - sum_index[sum] > longest_sub_array) longest_sub_array = i - sum_index[sum];
            } else {
                sum_index[sum] = i;
            }
        }
        
        return longest_sub_array;
        
    }
};
