class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        map<int, vector<int>> graphX;
        //set<vector<int>> edges;
        map<vector<int>,int> edges;
        for(vector<int> edge : connections) {
            edges[edge] = 1;
            //edges.insert(edge);
            graphX[edge[0]].push_back(edge[1]);
            graphX[edge[1]].push_back(edge[0]);
        }
        
        queue<int> q;
        q.push(0);
        int reverse_edges_count = 0;
        set<int> visited;
        visited.insert(0);
        
        while(!q.empty()) {
            int current_node = q.front();
            q.pop();
            
            for(int next_node : graphX[current_node]) {
                if(visited.find(next_node) == visited.end()) {
                    //if(edges.find({next_node, current_node}) == edges.end()) reverse_edges_count++;
                    if(!edges[{next_node, current_node}]) reverse_edges_count++;
                    visited.insert(next_node);
                    q.push(next_node);
                }
            }
        }
        
        return reverse_edges_count;
        
    }
};
