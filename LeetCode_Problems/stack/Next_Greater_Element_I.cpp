class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> stk;
        map<int,int> next_greater_num_map;
        vector<int> result;
        
        // Generate the next greater number map
        for(int i=0; i<nums2.size(); i++) {
            int current_num = nums2[i];
            
            if(stk.empty()) {
                stk.push(current_num);
            } else {
                while(!stk.empty() && stk.top() < current_num) {
                    next_greater_num_map[stk.top()] = current_num;
                    stk.pop();
                }
                
                stk.push(current_num);
            }
        }
        
        // Create the result from the generated map
        for(int i=0; i<nums1.size(); i++) {
            if(next_greater_num_map.find(nums1[i]) != next_greater_num_map.end()) {
                result.push_back( next_greater_num_map[nums1[i]] );
            } else {
                result.push_back(-1);
            }
        }
        
        return result;
        
    }
};
