class Solution {
    
   class Compare
    {
    public:
        bool operator() (pair<double,int> a, pair<double,int> b)
        {
            return a.second > b.second;
        }
    };
    
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        priority_queue< pair<int,int>, vector<pair<int,int>>, Compare > pq; // first = node name; second = best node dist
        map<int, pair<int,int>> vertex_info_table; // node -> best dist, came from
        map<int, set<pair<int,int>> > graphX; // node -> node_next, weight
        set<int> visited;
        int max_delay = INT_MIN;
        
        for(int node = 1; node<=n; node++) {
            vertex_info_table[node].first = INT_MAX; // best dist
            vertex_info_table[node].second = -1; // parent
        }
        
        for(vector<int> edge : times) {
            graphX[edge[0]].insert({edge[1], edge[2]});
        }
        
        pq.push({k,0});
        vertex_info_table[k].first = 0;
        vertex_info_table[k].second = -1;
        
        //Dijkstra's algo
        
        while(!pq.empty()) {
            
            pair<int,int> current_node_ = pq.top();
            int current_node = current_node_.first;
            int current_node_best_dist = current_node_.second;
            pq.pop();
            
            for(set<pair<int,int>>::iterator it = graphX[current_node].begin(); it != graphX[current_node].end(); it++) {
                
                pair<int,int> next_node_ = *it;
                int next_node = next_node_.first;
                int next_node_w = next_node_.second;
                
                if(vertex_info_table[next_node].second == current_node) continue;
                //if(visited.find(next_node) != visited.end()) continue;
                
                int next_node_dist = next_node_w + current_node_best_dist;
                int next_node_current_best_dist = vertex_info_table[next_node].first;
                
                if(next_node_dist < next_node_current_best_dist) {
                    vertex_info_table[next_node].first = next_node_dist;
                    vertex_info_table[next_node].second = current_node;
                    pq.push({next_node, next_node_dist});
                    
                    //if(max_delay < next_node_dist) max_delay = next_node_dist;
                }
                
            }
            
            //visited.insert(current_node);
            
        }
        
        for(int node = 1; node<=n; node++) {
            int node_dist_from_k = vertex_info_table[node].first;
            if(max_delay < node_dist_from_k) max_delay = node_dist_from_k;
        }
        
        if(max_delay == INT_MAX) return -1;
        
        return max_delay;
        
    }
};
