class Solution {
public:
    
    static bool compare(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        map< int, vector<pair<int,int>> > graphX;
        
        for(vector<int> edge : times) {
            //     from                 to     ,  weight
            graphX[edge[0]].push_back( {edge[1], edge[2]} );
        }
        
        int max_dist = INT_MIN;
        
        //Dijkstra's algo
        int start_node = k;
        map<int,int> completed_nodes;
        priority_queue<pair<int,int>, vector<pair<int,int>>, function<bool(pair<int,int>, pair<int,int>)> > pq(compare);
        pq.push( {start_node, 0} );
        
        while(!pq.empty()) {
            pair<int,int> node_and_dist = pq.top();
            pq.pop();
            
            int current_node = node_and_dist.first;
            int current_node_dist = node_and_dist.second;
            
            // Check if the node was already completed.
            if(completed_nodes.find(current_node) != completed_nodes.end()) continue;
            
            completed_nodes[current_node] = current_node_dist;
            
            if(max_dist < current_node_dist) max_dist = current_node_dist;
            
            
            for(pair<int,int> next_node_and_weight : graphX[current_node]) {
                int next_node = next_node_and_weight.first;
                int next_node_dist = current_node_dist + next_node_and_weight.second;
                
                if(completed_nodes.find(next_node) == completed_nodes.end()) {
                    pq.push( {next_node, next_node_dist} );
                }
                
            }
            
        }
        
        if(completed_nodes.size() < n) return -1;
        
        return max_dist;
        
    }
};
