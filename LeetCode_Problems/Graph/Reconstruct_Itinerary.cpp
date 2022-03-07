class Solution {
public:
    
    vector<string> result;
    set<pair<string, string>> visited;
    map<pair<string, string>, int> repeated_edge_counts; // We can have repeated edges in this problem hence a simple visited array is not enough
    int N;
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        map<string, vector<string>> graphX;
        
        N = tickets.size();
        
        for(vector<string> ticket : tickets) {
            graphX[ticket[0]].push_back(ticket[1]);
            repeated_edge_counts[ {ticket[0], ticket[1]} ] += 1;
        }
        
        for(vector<string> sv : tickets) {
            sort( graphX[sv[0]].begin(), graphX[sv[0]].end() );
        }
        
        dfs(graphX, "JFK", 0);
        
        reverse(result.begin(), result.end());
        
        return result;
        
    }
    
    
    void dfs(map<string, vector<string>> &graphX, string current_node, int edge_num) {
        
        for(string next_node : graphX[current_node]) {
            
            if(visited.find( {current_node, next_node} ) == visited.end()) {
                
                repeated_edge_counts[ {current_node, next_node} ] -= 1;
                
                if(repeated_edge_counts[ {current_node, next_node} ] <= 0) visited.insert( {current_node, next_node} );
                
                dfs(graphX, next_node, edge_num + 1);
            }

        }
        
        result.push_back(current_node);
        
    }
};
