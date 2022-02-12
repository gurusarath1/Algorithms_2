class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        map<string, map<string, double>> graphX;
        
        int i = 0;
        for(vector<string> edge : equations) {
            graphX[edge[0]][edge[1]] = values[i];
            graphX[edge[1]][edge[0]] = 1 / values[i];
            i++;
        }
        
        vector<double> result;
        set<string> visited;
        for(vector<string> query : queries) {
            visited.clear();
            double res = path_source_destination(graphX, query[0], query[1],  1, visited);
            result.push_back(res);
        }
        
        
        return result;
    }
    
    double path_source_destination(map<string, map<string, double>> &graphX, string &current_node, string &destination, double current_value, set<string> &visited) {
        
        if(current_node == destination) {
            
            if(graphX.find(current_node) == graphX.end()) return -1; 
            
            return current_value;
        }
        
        
        map<string, double>::iterator it;
        
        visited.insert(current_node);
        
        if(graphX.find(current_node) != graphX.end()) {
            
            it = graphX[current_node].begin();
            
            while(it != graphX[current_node].end()) {
                
                string next_node = it->first;
                double next_node_weight = it->second;
                
                if(visited.find(next_node) != visited.end()) {
                    it++;
                    continue;
                }
                
                double ret = path_source_destination(graphX, next_node, destination, current_value * next_node_weight, visited);
                
                if(ret != -1) return ret;
                
                it++;
            }
            
        }
        
        return -1;
    }
};
