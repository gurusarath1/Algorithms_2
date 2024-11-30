class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {

        /*
        deque is used instead of a vector because we need not keep track of visited edges by poping from deque
        */
        unordered_map<int, deque<int>> graph;
        unordered_map<int,int> in_degree;
        unordered_map<int,int> out_degree;

        for(vector<int> &e : pairs) {
            graph[e[0]].push_back(e[1]); // Add edge
            in_degree[e[1]] += 1;
            out_degree[e[0]] += 1;
        }

        int start_node = -1;
        int end_node = -1;
        // Find the Start Node
        for(auto node : out_degree) {
            if(out_degree[node.first] - in_degree[node.first] == 1) { // condition for start node
                start_node = node.first;
                break;
            }
        }

        // We can start from any node
        if(start_node == -1) {
            start_node = end_node = pairs[0][0]; // some random start (we end at the same node)
        }

        vector<int> eulerian_path;
        eulerian_path_circuit_dfs(start_node, graph, eulerian_path);

        // Build the edges from path
        vector<vector<int>> edges;
        for(int i=eulerian_path.size()-1; i>0; i--) {
            edges.push_back(vector<int>{eulerian_path[i], eulerian_path[i-1]});
        }

        return edges;
        
    }


    inline void eulerian_path_circuit_dfs(int current_node, unordered_map<int,deque<int>> &graph, vector<int> &eulerian_path) {

        while(graph[current_node].size()) {
            int next_node = graph[current_node].front();
            graph[current_node].pop_front(); // remove the edge. (don't visit the same edge again)
            eulerian_path_circuit_dfs(next_node, graph, eulerian_path);
        }

        eulerian_path.push_back(current_node);
    }

};
