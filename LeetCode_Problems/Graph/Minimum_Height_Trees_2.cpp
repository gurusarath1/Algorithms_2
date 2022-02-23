class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        //edge case
        vector<int> result;
        if(edges.size() == 0) {
            result.push_back(0);
            return result;
        }
        
        // Create the graph
        map<int, set<int>> graph;
        for(vector<int> edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        
        // add all nodes with only one connecting edge
        queue<int> q;
        for(pair<int, set<int>> p : graph) {
            if(p.second.size() == 1) {
                q.push(p.first);
            }
        }
        
        // Trim nodes layer by layer
        int untrimmed_nodes = n;
        while(untrimmed_nodes > 2) {
            
            int outer_layer_size = q.size();
            for(int i=0; i<outer_layer_size; i++) {
                int leaf_node = q.front();
                q.pop();
                
                // Get the node connected to this leaf node
                int connected_node = *graph[leaf_node].begin();
                graph[connected_node].erase(leaf_node);
                
                if(graph[connected_node].size() == 1) {
                    q.push(connected_node);
                }
            }
            untrimmed_nodes -= outer_layer_size;
            
        }
        
        // Last 1 or 2 nodes is the result
        while(!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        
        return result;
    }
};
