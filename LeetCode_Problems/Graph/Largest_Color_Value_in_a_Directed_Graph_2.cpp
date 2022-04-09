class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        map<int, vector<int>> graph;
        map<int, vector<int>> reverse_graph;
        queue<int> q;
        int n = colors.size();
        vector<int> indegree(n);
        
        int dp[n][26];
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<26; j++) {
                if(j == colors[i] - 'a') {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        
        for(vector<int> e : edges) {
            graph[e[0]].push_back(e[1]);
            reverse_graph[e[1]].push_back(e[0]);
        }
        
        for(int i=0; i<n; i++) {
            if(reverse_graph[i].size() == 0) {
                q.push(i);
            }
            indegree[i] = reverse_graph[i].size();
        }
        
        int visited = 0;
        
        int max_path = 1;
        while(!q.empty()) {
            int current_node = q.front();
            int current_node_color = colors[current_node];
            q.pop();
            visited += 1;
            
            for(int next_node : graph[current_node]) {
                
                for(int c=0; c<26; c++) {
                    int next_node_color = colors[next_node] - 'a';
                    if(c == next_node_color) {
                        dp[next_node][c] = max(dp[next_node][c], dp[current_node][c] + 1);
                    } else {
                        dp[next_node][c] = max(dp[next_node][c], dp[current_node][c]);
                    }
                    
                    if(max_path < dp[next_node][c]) {
                        max_path = dp[next_node][c];
                    }
                }
                
                indegree[next_node] -= 1;
                
                if(indegree[next_node] == 0) {
                    q.push(next_node);
                }
            }
        }
        
        if(visited < n) return -1;
        
        return max_path;
        
    }
};
