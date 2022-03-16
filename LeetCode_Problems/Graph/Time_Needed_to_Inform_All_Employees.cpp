class Solution {
public:
    
    int max_delay = INT_MIN;
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        map< int, vector<pair<int,int>> > graphX;
        
        for(int i=0; i<n; i++) {
            graphX[manager[i]].push_back( {i,informTime[i]} );
        }
        
        
        dfs_all_paths_tree(graphX, -1, 0);
        
        return max_delay;
        
        
    }
    
    void dfs_all_paths_tree(map< int, vector<pair<int,int>> > &graphX, int current_node, int current_delay) {
        
        if(graphX[current_node].size() == 0) {
            if(current_delay > max_delay) {
                max_delay = current_delay;
            }
            
            return;
        }
        
        for(pair<int,int> p : graphX[current_node]) {
            int next_node = p.first;
            int next_delay = p.second;
            
            dfs_all_paths_tree(graphX, next_node, current_delay + next_delay);
        }
        
    }
    
};
