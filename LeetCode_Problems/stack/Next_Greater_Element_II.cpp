class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        vector<int> result(nums.size(), -1);
        vector<int> circular_nums;
        stack<int> stk;
        
        // Repeat the array twice
        for(int i=0; i<2; i++) {
            for(int num : nums) {
                circular_nums.push_back(num);
            }
        }
        
        // Run Next Greater Element I algorithm
        for(int i=0; i<circular_nums.size(); i++) {
            while(!stk.empty() && circular_nums[i] > circular_nums[stk.top()] ) {
                
                // Wraparound the index
                result[stk.top() % nums.size()] = circular_nums[i];
                stk.pop();
            }

            stk.push(i);
        }
        
        return result;
    }
};
