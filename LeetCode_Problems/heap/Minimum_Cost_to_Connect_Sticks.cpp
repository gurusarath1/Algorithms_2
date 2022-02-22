class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int> pq;
        
        for(int s : sticks) {
            pq.push(-s);
        }
        
        int total_cost = 0;
        while(!pq.empty()) {
            int stick_len1 = -pq.top();
            pq.pop();
            
            if(pq.size() == 0) break;
            
            int stick_len2 = -pq.top();
            pq.pop();
            
            total_cost += stick_len1 + stick_len2;
            pq.push(-(stick_len1 + stick_len2));
        }
        
        return total_cost;
    }
};
