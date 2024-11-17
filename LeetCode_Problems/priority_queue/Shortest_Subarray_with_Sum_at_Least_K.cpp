class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

        long long current_sum = 0;
        int shortest_len = INT_MAX;
        for(int i=0; i<nums.size(); i++) {

            current_sum += nums[i];

            if(current_sum >= k && shortest_len > i+1) {
                shortest_len = i+1;
            }

            while(!pq.empty() && (current_sum - pq.top().first) >= k) {

                int sub_array_len = i - pq.top().second;

                if(sub_array_len < shortest_len) {
                    shortest_len = sub_array_len;
                }

                pq.pop();
            }

            pq.emplace(current_sum, i);

        }

        if(shortest_len == INT_MAX) return -1;

        return shortest_len;
        
    }
};
