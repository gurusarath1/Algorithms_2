class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int num_rooms = rooms.size();
        set<int> visited;
        return dfs(rooms, 0, num_rooms, visited);
    }
    
    bool dfs(vector<vector<int>> &rooms, int current_room, int num_rooms, set<int> &visited) {
        
        visited.insert(current_room);
        
        if(visited.size() == num_rooms) {
            return true;
        }
        
        bool found_all = false;
        for(int next_room : rooms[current_room]) {
            if(visited.find(next_room) == visited.end()) {
                found_all = dfs(rooms, next_room, num_rooms, visited);
                if(found_all) break;
            }
        }
        
        return found_all;
        
    }
};
