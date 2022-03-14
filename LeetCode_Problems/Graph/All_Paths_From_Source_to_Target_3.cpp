class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int start_node = 0;
        int destination_node = graph.size() - 1;
        
        vector<int> current_path;
        vector<vector<int>> all_paths;
        
        dfs_dag(graph, start_node, destination_node, current_path, all_paths);
        
        return all_paths;
    }
    
    void dfs_dag(vector<vector<int>>& graph, int current_node, int destination_node, vector<int> &current_path, vector<vector<int>> &all_paths) {
        
        current_path.push_back(current_node);
        
        // Goal test
        if(current_node == destination_node) {
            all_paths.push_back(current_path);
        }
        
        // goto all next nodes
        for(int next_node : graph[current_node]) {
            dfs_dag(graph, next_node, destination_node, current_path, all_paths);
        }
        
        current_path.pop_back();
        
    }
};
