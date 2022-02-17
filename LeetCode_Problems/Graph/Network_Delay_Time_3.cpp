class Solution {
    
public:
    
    map<int,int> node_best_times;
    map< int, vector<pair<int,int>> > graphX;
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        for(int i=1; i<=n; i++){
            node_best_times[i] = INT_MAX;
        }
        
        for(vector<int> edge : times) {
            graphX[edge[0]].push_back({edge[1], edge[2]});
        }
        
        //DFS algo
        dfs(k,-1, 0);

        int max_delay = INT_MIN;
        for(int i=1; i<=n; i++) {
            if(node_best_times[i] > max_delay) max_delay = node_best_times[i];
        }
        
        if(max_delay == INT_MAX) return -1;
        
        return max_delay;
        
    }
    
    
    void dfs(int current_node, int parent_node, int current_time) {
        
        node_best_times[current_node] = current_time;
        
        for(int i=0; i<graphX[current_node].size(); i++) {
            int next_node = graphX[current_node][i].first;
            int edge_weight = graphX[current_node][i].second;
            
            if(next_node == parent_node) continue;
                
                if(current_time + edge_weight < node_best_times[next_node]) {
                    dfs(next_node, current_node, current_time + edge_weight);
                }

        }
        
        return;
        
    }
};
