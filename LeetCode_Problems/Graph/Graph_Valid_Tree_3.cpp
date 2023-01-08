class Solution {
public:


    bool validTree(int n, vector<vector<int>>& edges) {

        // Create the undirected graph
        map<int, vector<int>> graph;
        for(vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        set<int> visited_set;

        // Check if cycle exist. starting from node 0
        bool cycle_flag = dfs(-1, 0, visited_set, graph);

        // Check if it is a forest
        return cycle_flag && (visited_set.size() == n);
        
    }

    bool dfs(int prev_node, int current_node, set<int> &visited_nodes, map<int, vector<int>> &graph) {

        if(visited_nodes.find(current_node) != visited_nodes.end()) {
            // Cycle detected
            return false;
        }

        // Record the nodes along this current path
        visited_nodes.insert(current_node);

        for(int next_node : graph[current_node]) {

            if(next_node == prev_node) {
                // Dont go back (undirected graph)
                continue;
            }

            bool res = dfs(current_node, next_node, visited_nodes, graph);

            // Return if cycle was detected down this path
            if(res == false) return false;
        }

        // No cycle detected along this path
        return true;
    }
};
