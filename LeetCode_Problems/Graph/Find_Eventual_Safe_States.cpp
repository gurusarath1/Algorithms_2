class Solution {
public:
    map<int,int> node_type;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        #define UNKNOWN_NODE 0
        #define SAFE_NODE 1
        #define UNSAFE_NODE 2
        
        int n = graph.size();
        set<int> visited;
        
        // mark all nodes as unclassified
        for(int i=0; i<n; i++) {
            node_type[i] = UNKNOWN_NODE;
        }
        
        // perform dfs on all unclassified nodes
        for(int i=0; i<n; i++) {
            if(node_type[i] == UNKNOWN_NODE) dfs(graph, i, visited);
        }
        
        // generate the result vector 
        // keys of the map is already sorted
        vector<int> result;
        for(pair<int,int> n_t : node_type) {
            int node = n_t.first;
            int type = n_t.second;
            
            if(type == SAFE_NODE) {
                result.push_back(node);
            }
        }
        
        return result;
        
    }
    
    int dfs(vector<vector<int>> &graph, int current_node, set<int> &visited) {
        
        if(node_type[current_node] != UNKNOWN_NODE) { // if a node was already classified -> return node type from memo
            return node_type[current_node];
        }
        
        if(visited.find(current_node) != visited.end()) { // Back edge
            node_type[current_node] = UNSAFE_NODE;
            return UNSAFE_NODE;
        }
        
        if(graph[current_node].size() == 0) { // reached a terminal node
            node_type[current_node] = SAFE_NODE;
            return SAFE_NODE;
        }
        
        visited.insert(current_node);
        
        // Traverse all paths
        for(int next_node : graph[current_node]) {
            int path_type = dfs(graph, next_node, visited);
            
            // even if one path is unsafe, the whole node is unsafe
            if(path_type == UNSAFE_NODE) {
                node_type[current_node] = UNSAFE_NODE;
                return UNSAFE_NODE;                
            }
        }
        
        visited.erase(current_node);
        
        // if we successfully existed the for loop then all paths were safe
        node_type[current_node] = SAFE_NODE;
        return SAFE_NODE;
        
    }
};
