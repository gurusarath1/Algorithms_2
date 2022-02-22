class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;
        
        for(int stone : stones) {
            pq.push(stone);
        }
        
        while(pq.size() >= 2) {
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();
            
            if(stone1 == stone2) {
                ;
            } else {
                int diff = stone1 - stone2;
                pq.push(diff);
            }
        }
        
        if(pq.empty()) return 0;
        
        return pq.top();
        
    }
};
