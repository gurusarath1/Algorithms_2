class Solution {
public:

    static bool cmp(vector<int> &a, vector<int> &b) {
        if(a[0] < b[0]) {
            return false;
        } else if(a[0] > b[0]) {
            return true;
        } else {
            if(a[1] < b[1]) {
                return false;
            } else {
                return true;
            }
        }
        return false; // unreachable
    }

    long long findScore(vector<int>& nums) {

        priority_queue < vector<int>, vector<vector<int>>, function<bool(vector<int>&, vector<int>&)> > pq(cmp);

        for(int i=0; i<nums.size(); i++) {
            pq.push(vector<int>{nums[i], i});
        }

        long long score = 0;
        unordered_set<int> marked;
        while(!pq.empty()) {

            const vector<int> &q = pq.top();
            int idx = q[1];

            if(marked.find(idx) == marked.end()) {
                score += q[0];
                marked.insert(idx);
                marked.insert(idx+1);
                marked.insert(idx-1);
            }

            pq.pop();
        }

        return score;
        
    }
};
