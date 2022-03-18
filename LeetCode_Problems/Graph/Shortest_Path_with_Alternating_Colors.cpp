class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        #define RED -1
        #define BLUE 1
        #define BOTH 0
        
        vector<vector<int>> adj(n, vector<int>(n, -n));
        
        for(vector<int> edge : redEdges) {
            adj[edge[0]][edge[1]] = RED;
        }
        
        for(vector<int> edge : blueEdges) {
            if(adj[edge[0]][edge[1]] == RED)
                adj[edge[0]][edge[1]] = BOTH;
            else 
                adj[edge[0]][edge[1]] = BLUE;
        }
        
        vector<int> result(n,-1);
        result[0] = 0;
        
        queue<pair<int,int>> q;
        q.push({0,RED});
        q.push({0,BLUE});
        
        set<pair<int,int>> visited;
        int dist = 0;
        while(!q.empty()) {
            
            int layer_size = q.size();
            dist++;
            for(int i=0; i<layer_size; i++) 
            {
                auto current_node = q.front();
                q.pop();
                int node = current_node.first;
                int color = current_node.second;
                int opposite_color = -color;

                for(int next_node=0; next_node<n;  next_node++) {
                    if( (adj[node][next_node] == opposite_color || adj[node][next_node] == BOTH) && visited.find({next_node, opposite_color}) == visited.end() ) {
                        visited.insert({next_node, opposite_color});
                        q.push({next_node, opposite_color});
                        if(result[next_node] == -1 || result[next_node] > dist) {
                            result[next_node] = dist;
                        }
                    }
                }
            }
        }
        
        return result;
    }
};
