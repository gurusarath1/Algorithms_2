class Solution {
public:
    // TIME LIMIT EXCEEDED 40/83
    int largestColorValue(map<char,int> &freq) {
        
        int max_freq = 0;
        
        for(pair<char,int> p : freq) {
            if(p.second > max_freq) {
                max_freq = p.second;
            }
        }
        
        return max_freq;
    }
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        map<int, vector<int>> graph;
        map<int, vector<int>> reverse_graph;
        queue<int> q; // start nodes
        
        int n = colors.size();
        
        for(vector<int> e : edges) {
            graph[e[0]].push_back(e[1]);
            reverse_graph[e[1]].push_back(e[0]);
        }
        
        for(int i=0; i<=n-1; i++) {
            if(reverse_graph[i].size() == 0) {
                q.push(i);
            }
        }
        
        set<int> visited;
        map<char, int> freq;
        int max_val = INT_MIN;
        vector<int> path;
        while(!q.empty()) {
            int current_start = q.front();
            q.pop();
            
            visited.clear();
            freq.clear();
            int path_val = dfs(current_start, colors, graph, visited, freq);//, path);
            
            if(path_val == -1) {
                return -1;
            }
            
            if(path_val > max_val) {
                max_val = path_val;
            }
        }
        
        if(max_val == INT_MIN) return -1;
        
        return max_val;
        
    }
    
    int dfs(int current_node, string &colors, map<int, vector<int>> &graph, set<int> &visited, map<char, int> &freq) { //, vector<int> path) {
        
        //path.push_back(current_node);
        
        if(visited.find( current_node ) != visited.end()) {
            return -1;
        }
        
        visited.insert( current_node );
        freq[colors[current_node]] += 1;
        
        if(graph[current_node].size() == 0) {
            int path_val = largestColorValue(freq);
            
            visited.erase(current_node); 
            freq[colors[current_node]] -= 1;
            
            return path_val;
        }
        
        int max_val = INT_MIN;
        for(int next_node : graph[current_node]) {
            
            int path_val = dfs(next_node, colors, graph, visited, freq); //, path);
            
            if(path_val == -1) {
                visited.erase(current_node); 
                freq[colors[current_node]] -= 1;
                return -1;
            }
            
            if(path_val > max_val) {
                max_val = path_val;
            }
            
        }
        
        
        visited.erase(current_node); 
        freq[colors[current_node]] -= 1;
        return max_val;
        
    }
    
};
