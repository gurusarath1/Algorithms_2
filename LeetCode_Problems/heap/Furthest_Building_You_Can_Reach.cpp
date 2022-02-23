class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue<int> pq;
        int prev_height = heights[0];
        
        int num_ladders = ladders;
        int num_bricks = bricks;
        int i = 1;
        for(; i<heights.size(); i++) {
            int current_height = heights[i];
            int gap = current_height - prev_height;
            
            if(gap <= 0) {
                prev_height = current_height;
                continue;
            }
            
            if(num_ladders > 0) {
                num_ladders--;
                pq.push(-gap);
            } else {
                if(!pq.empty() && gap > -pq.top()) {
                    // use ladder
                    if(-pq.top() <= num_bricks) {
                        num_bricks -= -pq.top();
                        pq.pop();
                        pq.push(-gap);
                    } else {
                        break;
                    }
                } else {
                    if(num_bricks >= gap) {
                        num_bricks -= gap;
                    } else {
                        break;
                    }
                }
            }
            
            prev_height = current_height;
        }
        
        return i-1;
        
    }
};
