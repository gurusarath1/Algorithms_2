class Solution {
public:
    
    vector<vector<int>> result;
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<int> path;
        traverse(graph, 0, path);
        
        return result;
        
    }
    
    void traverse(vector<vector<int>>& graph, int current_node, vector<int> &path) {
        
        path.push_back(current_node);
        
        if(current_node == graph.size() - 1) result.push_back(path);
        
        for(int i=0; i<graph[current_node].size(); i++) {
            traverse(graph, graph[current_node][i], path);
            path.pop_back();
        }
        
    }
    
};
