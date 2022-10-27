class Solution {
public:
    
    vector<vector<int>> result;
    int next_id = 0;
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        map<int, vector<int>> graph;
        
        for(vector<int> &edge : connections) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n);
        vector<int> lowest_ids(n, INT_MAX);
        
        targans_algo(graph, 0, -1, visited, lowest_ids);
        
        return result;
        
    }
    
    void targans_algo(map<int, vector<int>> &graph, int current_node, int parent_node, vector<bool> &visited, vector<int> &lowest_ids) {
        
        lowest_ids[current_node] = next_id;
        next_id++;
        visited[current_node] = true;
        int initial_lowest_id = lowest_ids[current_node];
        
        for(int next_node : graph[current_node]) {
            
            if(next_node == parent_node) continue;
            
            if(!visited[next_node]) {
                targans_algo(graph, next_node, current_node, visited, lowest_ids);
            }
            lowest_ids[current_node] = min(lowest_ids[current_node], lowest_ids[next_node]);

            if(initial_lowest_id < lowest_ids[next_node]) {
                result.push_back({current_node, next_node});
            }
        }
        
        
        return;
    }
    
    
    
};
