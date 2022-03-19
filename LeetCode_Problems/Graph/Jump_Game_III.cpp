class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        map<int, vector<int>> graphX;
        int max_node = arr.size() - 1;
        
        for(int i=0; i<= max_node; i++) {
            
            if(arr[i] + i <= max_node) {
                graphX[i].push_back(arr[i] + i);
            }
            
            if(i - arr[i] >= 0) {
                graphX[i].push_back(i - arr[i]);
            }
        }
        
        queue<int> q;
        q.push(start);
        
        set<int> visited;
        visited.insert(start);
        
        while(!q.empty()) {
            int current_node = q.front();
            q.pop();
            
            if(arr[current_node] == 0) return true;
            
            for(int next_node : graphX[current_node]) {
                if(visited.find(next_node) == visited.end()) {
                    visited.insert(next_node);
                    q.push(next_node);
                }
            }
            
        }
        
        return false;
        
    }
};
