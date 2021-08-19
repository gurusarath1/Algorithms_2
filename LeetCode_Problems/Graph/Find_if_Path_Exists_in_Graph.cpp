class Solution {
public:
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        
        map<int, set<int>> graph;
        
        for(vector<int> edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        
        set<int> visited;
        
        return traverse(graph, start, end, visited);
        
    }
    
    bool traverse(map<int, set<int>> &graph, int current_node, int end, set<int> &visited) {
        
        if(current_node == end) return true;
        
        visited.insert(current_node);
        
        set<int>::iterator it = graph[current_node].begin();
        
        bool path_found = false;
        while(it != graph[current_node].end()) {
            
            if(visited.find(*it) == visited.end()) { 
                path_found = traverse(graph, *it, end, visited);
            }
            
            if(path_found) return true;
            
            it++;
        }
        
        return false;
        
    }
};
