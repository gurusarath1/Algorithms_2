class Solution {
public:
    
    // Time limit exceeded
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        

        vector<int> x;
        x.reserve(n);
        vector<vector<int>> graph(n, x);
        
        for(vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int height;
        int min_height = INT_MAX;
        int heights_map[n];
        for(int i=0; i<n; i++) {
            height = traverse(graph, i, -1);
            min_height = min(min_height, height);
            heights_map[i] = height;
        }
        
        vector<int> result;
        result.reserve(n);
        for(int i=0; i<n; i++) {
            if(heights_map[i] == min_height) {
                result.push_back(i);
            }
        } 
        
        return result;
        
    }
    
    int traverse(vector<vector<int>> &graph, int current_node, int parent) {
        
        int path_len = 0;
        int max_path_len = 0;
        for(int i=0; i<graph[current_node].size(); i++) {
            if(graph[current_node][i] != parent) {
                path_len =  traverse(graph, graph[current_node][i], current_node);
                max_path_len = max(max_path_len, path_len);
            }
        }
        
        return max_path_len + 1;
    }
    
    
};
