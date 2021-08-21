class Solution {
public:
    
    bool validTree(int n, vector<vector<int>>& edges) {
        
        map<int, vector<int>> graph;
        
        for(vector<int>edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        set<int> visited;
        
        bool ret = isTree(graph, 0, visited, -1);
        
        if(ret) {
            // Check if it is a forest
            if(visited.size() != n) return false;
            else return true;
            
        } else {
            return false;
        }
        
    }
    
    
    bool isTree(map<int, vector<int>> &graph, int current_node, set<int> &visited, int parent) {
        
        visited.insert(current_node);
        
        for(int i=0; i<graph[current_node].size(); i++) {
            
            if(visited.find(graph[current_node][i]) != visited.end()) {
                if( parent == graph[current_node][i] ) {
                    continue;
                } else {
                    return false;
                }
            } 
            
            bool isTreeRet = isTree(graph, graph[current_node][i], visited, current_node);
            
            if(!isTreeRet) return false;
        }
        
        return true;
        
    }
};
