class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> stk;
        map<int,int> mp;

        for(int i=0; i<nums2.size(); i++) {

            while(!stk.empty() && stk.top() < nums2[i]) { // monotonic stack logic
                int num = stk.top();
                stk.pop();
                mp[num] = nums2[i];
            }
            stk.push(nums2[i]);
        }

        // Build result array
        vector<int> res(nums1.size(), -1);
        for(int i=0; i<nums1.size(); i++) {

            int n = nums1[i];

            if(mp.find(n) == mp.end()) {
                ;
            } else {
                res[i] = mp[n];
            }
        }

        return res;
    }
};
