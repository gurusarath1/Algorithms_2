class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int> stk;
        vector<int> result(nums.size());

        for(int j=0; j<2; j++) {

            for(int i=nums.size() - 1; i >= 0; i--) {

                while(!stk.empty() && nums[i] >= nums[stk.top()]) {
                    stk.pop();
                }

                if(stk.empty()) {
                    result[i] = -1;
                } else {
                    result[i] = nums[stk.top()];
                }

                stk.push(i);
            }
            
            ;
        }
        
        return result;
    }
};
