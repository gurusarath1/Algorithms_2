class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int> nodes(n+1,INT_MAX);
        map<int, vector<pair<int,int>>> graphX;
        
        for(vector<int> edge : times) {
            graphX[edge[0]].push_back( {edge[1], edge[2]} );
        }
        
        queue<int> q;
        set<int> currently_in_q;
        q.push(k);
        currently_in_q.insert(k);
        
        nodes[k] = 0;
        //SPFA algorithm
        
        while(!q.empty()) {
            
            int current_node = q.front();
            q.pop();
            currently_in_q.erase(current_node);
            
            for(int i=0; i<graphX[current_node].size(); i++) {
                int to_node = graphX[current_node][i].first;
                int current_dist = nodes[to_node];
                int new_dist;
                
                if(nodes[current_node] != INT_MAX) {
                    new_dist = nodes[current_node] + graphX[current_node][i].second;
                } else {
                    new_dist = INT_MAX;
                }
                
                if(current_dist > new_dist) {
                    if(currently_in_q.find(to_node) == currently_in_q.end()) {
                        q.push(to_node);
                        currently_in_q.insert(to_node);
                    }
                    
                    nodes[to_node] = new_dist;
                }
            }
            
        }
        
        
        int max_dist = INT_MIN;
        for(int i=1; i<n+1; i++) {
            if(max_dist < nodes[i]) max_dist = nodes[i];
        }
        
        if(max_dist == INT_MAX) return -1;
        
        return max_dist;
    }
};
