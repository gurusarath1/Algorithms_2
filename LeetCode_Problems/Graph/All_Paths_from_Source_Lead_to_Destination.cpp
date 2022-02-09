class Solution {
public:
    map<int, vector<int>> graphX;
    
    #define NODE_UNVISITED 0
    #define NODE_PROCESSING 1
    #define NODE_PROCESSING_COMPLETE 2
    
    int g_source;
    int g_destination;
    
    vector<int> visited_level;
    
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        
        g_source = source;
        g_destination = destination;

        for(vector<int> edge : edges) {
            graphX[edge[0]].push_back(edge[1]);
        }
        
        visited_level.resize(n+1, NODE_UNVISITED);
        
        return traverse_graph(g_source);
        
    }
    
    bool traverse_graph(int current_node) {
        
        if(current_node == g_destination && graphX[current_node].size() == 0) return true;
        
        if(graphX[current_node].size() == 0) return false;
        
        if(visited_level[current_node] == NODE_PROCESSING) return false;
        
        visited_level[current_node] = NODE_PROCESSING;
        
        for(int node : graphX[current_node]) {
            if(!traverse_graph(node)) {
                return false;
            }
        }
        
        visited_level[current_node] = NODE_PROCESSING_COMPLETE;
        
        return true;
    }
};
