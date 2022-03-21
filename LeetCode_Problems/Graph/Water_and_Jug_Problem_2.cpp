class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        
        if(jug1Capacity + jug2Capacity < targetCapacity) return false;
        
        queue<int> q;
        q.push(0);
        
        vector<int> next_qtys = {jug1Capacity, -jug1Capacity, jug2Capacity, -jug2Capacity};
        set<int> visited;
        visited.insert(0);
        while(!q.empty()) {
            int qty = q.front();
            q.pop();
            
            if(qty == targetCapacity) return true;
            
            for(int diff : next_qtys) {
                int next_qty = qty + diff;
                
                if(next_qty < 0 || next_qty > jug1Capacity + jug2Capacity || visited.find(next_qty) != visited.end()) continue;
                
                q.push(next_qty);
                visited.insert(next_qty);
                
            }
            
        }
        
        return false;
    }
};
