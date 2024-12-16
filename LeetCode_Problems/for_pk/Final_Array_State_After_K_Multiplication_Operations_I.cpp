class Solution {
public:

    static bool cmp(vector<int>&a, vector<int>&b) {
        if(a[0] < b[0]) {
            return false;
        } else if(a[0] > b[0]) {
            return true;
        } else if(a[0] == b[0]) {
            if(a[1] < b[1]) {
                return false;
            } else {
                return true;
            }
        }

        return true; // unreachable
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {

        priority_queue<vector<int>, vector<vector<int>>, function<bool(vector<int>&, vector<int>&)>> pq(cmp);

        vector<int> ret(nums.size());

        for(int i=0; i<nums.size(); i++) {
            pq.push(vector<int>{nums[i], i});
        }

        for(int i=0; i<k; i++) {
            vector<int> item = pq.top();
            pq.pop();
            item[0] = item[0] * multiplier;
            pq.push(item);
        }

        while(!pq.empty()) {
            vector<int> item = pq.top();
            pq.pop();
            ret[item[1]] = item[0];
        }

        return ret;
        
    }
};
