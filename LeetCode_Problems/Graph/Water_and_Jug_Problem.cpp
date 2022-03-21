class Solution {
  
  // TIME LIMIT EXCEDED
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        
        set<vector<int>> visited;
        
        return recurse(0, 0, jug1Capacity, jug2Capacity, targetCapacity, visited);
    }
    
    bool recurse(int q1, int q2, int jug1Capacity, int jug2Capacity, int target, set<vector<int>> &visited) {
        
        int current_total_quantity = q1 + q2;
        vector<int> current_state = {q1,q2};
        
        if(visited.find(current_state) != visited.end()) return false;
        
        int jug1_can_hold_more = jug1Capacity - q1;
        int jug2_can_hold_more = jug2Capacity - q2;
        
        if(q1 == target || q2 == target || current_total_quantity == target) return true;
        
        visited.insert(current_state);
        
        bool result = false;
        
        
        // Fill jug1
        if(q1 < jug1Capacity)
            result |= recurse(jug1Capacity, q2, jug1Capacity, jug2Capacity, target, visited);
        if(result) return true;
        
        // Fill jug2
        if(q2 < jug2Capacity)
            result |= recurse(q1, jug2Capacity, jug1Capacity, jug2Capacity, target, visited);
        if(result) return true;
        
        // Empty jug 2
        if(q2 > 0)
            result |= recurse(q1, 0, jug1Capacity, jug2Capacity, target, visited);
        if(result) return true;

        // Empty jug 1
        if(q1 > 0)
            result |= recurse(0, q2, jug1Capacity, jug2Capacity, target, visited);
        if(result) return true;

        // jug1 -> jug2
        if(jug2_can_hold_more > 0 && q1 > 0)
            if(jug2_can_hold_more > q1)
                result |= recurse(0, q2 + q1, jug1Capacity, jug2Capacity, target, visited);
            else
                result |= recurse(q1 - jug2_can_hold_more, jug2Capacity, jug1Capacity, jug2Capacity, target, visited);
        if(result) return true;
        
        // jug2 -> jug1
        if(jug1_can_hold_more > 0 && q2 > 0)
            if(jug1_can_hold_more > q2)
                result |= recurse(q2 + q1, 0, jug1Capacity, jug2Capacity, target, visited);
            else
                result |= recurse(jug1Capacity, q2 - jug1_can_hold_more, jug1Capacity, jug2Capacity, target, visited);
        
        
        return result;
    }
};
