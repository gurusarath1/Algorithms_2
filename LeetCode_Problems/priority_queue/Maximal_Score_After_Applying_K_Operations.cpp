class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(int n : nums) {
            pq.push(n);
        }

        long long result = 0;
        for(int i=0; i<k; i++) {
            int top = pq.top();
            pq.pop();

            result += top;
            pq.push(ceil((double)top / 3.0));
        }

        return result;
    }
};
