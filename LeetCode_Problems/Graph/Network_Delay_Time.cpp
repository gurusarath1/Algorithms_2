class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int> nodes(n+1,INT_MAX);
        
        nodes[k] = 0;
        //Bellman ford algo
        for(int i=0; i<n-1; i++) {
            bool no_update = true;
            for(vector<int> edge : times) {
                int current_best_dist = nodes[edge[1]];
                int new_dist;//nodes[edge[0]] + edge[2];
                
                if(nodes[edge[0]] != INT_MAX)
                    new_dist = nodes[edge[0]] + edge[2];
                else
                    new_dist = INT_MAX;
                
                if(new_dist < current_best_dist) {
                    nodes[edge[1]] = new_dist;
                    no_update = false;
                }
            }
            
            if(no_update) break; //It may not be always required to run N-1 times
        }
        
        int max_dist = INT_MIN;
        for(int i=1; i<n+1; i++) {
            if(max_dist < nodes[i]) max_dist = nodes[i];
        }
        
        if(max_dist == INT_MAX) return -1;
        
        return max_dist;
    }
};
