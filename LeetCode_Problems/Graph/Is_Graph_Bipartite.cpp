class Solution {
public:
    
    #define NO_COLOR 0
    #define RED_COLOR 1
    #define GREEN_COLOR -1
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<int> colors(n, NO_COLOR);
        
        for(int i=0; i<n; i++) {
            if(colors[i] == NO_COLOR) {
                if(!coloring_dfs(i, RED_COLOR, colors, graph)){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool coloring_dfs(int current_node, int current_color, vector<int> &colors, vector<vector<int>>& graph) {
        
        if(colors[current_node] == NO_COLOR) {
            // New not to explore
            colors[current_node] = current_color;
        } else if(colors[current_node] != current_color) {
            // Mismatch in color
            return false;
        } else {
            // Same color as the current color // No need to proceed as it was already explored
            return true;
        }
        
        for(int next_node : graph[current_node]) {
            if(!coloring_dfs(next_node, -current_color, colors, graph)) {
                return false;
            }
        }
        
        return true;
    }
};
