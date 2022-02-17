class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        int dp[k+2][n];
        
        map<int, vector<pair<int,int>>> graphX;
        
        for(vector<int> edge : flights) {
            graphX[edge[1]].push_back( {edge[0], edge[2]} ); // graphX[node] = { {incoming node,  weight of edge} }
        }
        
        for(int i=0; i<n; i++) {
            if(i != src)
                dp[0][i] = INT_MAX;
            else
                dp[0][i] = 0;
        }
        
        for(int i=1; i<=k+1; i++) {
            for(int j=0; j<n; j++) {
                dp[i][j] = INT_MAX;
            }
        }
        
        for(int i=1; i<=k+1; i++) {
            for(int current_node=0; current_node<n; current_node++) {
                
                dp[i][current_node] = dp[i-1][current_node];
                for(int m=0; m<graphX[current_node].size(); m++){
                    
                    int from_node = graphX[current_node][m].first;
                    int from_node_to_current_node_weight = graphX[current_node][m].second;
                    
                    int next_cost;
                    
                    if(dp[i-1][from_node] == INT_MAX) {
                        next_cost = INT_MAX;
                    } else {
                        next_cost = dp[i-1][from_node] + from_node_to_current_node_weight;
                    }
                    
                    dp[i][current_node] = min(dp[i][current_node], next_cost);
                }
            }
        }
        
        if(dp[k+1][dst] == INT_MAX) return -1;
        
        return dp[k+1][dst];
    }
};
