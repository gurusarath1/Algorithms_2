class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        set<int> visited;
        
        for(vector<int> edge : edges) {
            
            if(visited.find(edge[0]) != visited.end()) return edge[0];
            if(visited.find(edge[1]) != visited.end()) return edge[1];
            
            visited.insert(edge[0]);
            visited.insert(edge[1]);
            
        }
        
        return 0;
    }
};
