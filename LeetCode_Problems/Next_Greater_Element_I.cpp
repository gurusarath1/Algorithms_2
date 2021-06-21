class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        map<int,int> nextGreaterMap;
        stack<int> numsStack;
        vector<int> ret_array;
        
        numsStack.push(nums2[0]);
        for(int i=1; i<nums2.size(); i++) {
            
            while(!numsStack.empty() && i < nums2.size() && nums2[i] < numsStack.top()) {
                numsStack.push(nums2[i]);
                i++;
            }
            
            if(i >= nums2.size()) break;
            
            while(!numsStack.empty() && nums2[i] > numsStack.top()) {
                nextGreaterMap[numsStack.top()] = nums2[i];
                numsStack.pop();
            }
            
            numsStack.push(nums2[i]);
        }
        
        for(int x : nums1) {
            if(nextGreaterMap.find(x) != nextGreaterMap.end()) {
                ret_array.push_back(nextGreaterMap[x]);
            } else {
                ret_array.push_back(-1);
            }
        }
        
        return ret_array;
        
    }
};
