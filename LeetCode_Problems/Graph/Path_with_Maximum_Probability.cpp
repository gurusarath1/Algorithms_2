class Solution {
public:
    
    static bool compare(pair<int, double> &a, pair<int, double> &b) {
        return a.second < b.second;
    }
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        map<int, vector<pair<int, double>>> graphX;
        vector<bool> visited(n, false);
        
        for(int i=0; i<edges.size(); i++) {
            graphX[edges[i][0]].push_back( {edges[i][1], succProb[i]} );
            graphX[edges[i][1]].push_back( {edges[i][0], succProb[i]} );
        }
        
        // Djikstra's algo
        priority_queue< pair<int,double>, vector<pair<int,double>> , function<bool(pair<int, double>&, pair<int, double>&)> > q(compare);
        
        q.push({start, 1.0});
        
        while(!q.empty()) {
            
            int current_node = q.top().first;
            double current_prob = q.top().second;
            q.pop();
            
            if(current_node == end) {
                return current_prob;
            }
            
            if(visited[current_node] == true) {
                continue;
            }
            
            visited[current_node] = true;
            
            for(pair<int,double> p : graphX[current_node]) {
                
                int next_node = p.first;
                double succ_prob = p.second * current_prob;
                
                if(visited[next_node] == true) {
                    continue;
                }
                
                q.push({next_node, succ_prob});
            }
            
        }
        
        return 0;
        
    }
};
