class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {

        vector<int> res;
        vector<vector<int>> graph(n);

        for(int i=0; i<n-1; i++) {
            graph[i].push_back(i+1);
        }

        for(vector<int> &qry : queries) {
            graph[qry[0]].push_back(qry[1]);

            queue<int> q;
            q.push(0);
            vector<bool> added(n, false);
            added[0] = true;
            int shortest_path = 0;
            int done = false;
            
            while(!q.empty()) {

                int num_next_nodes = q.size();

                for(int i=0; i<num_next_nodes; i++) {
                    int current_node = q.front();
                    
                    if(current_node == n-1) {
                        res.push_back(shortest_path);
                        done = true;
                        break;
                    }

                    for(int next : graph[current_node]) {
                        if(added[next] == false) {
                            q.push(next);
                            added[next] = true;
                        }
                    }

                    q.pop();
                }

                if(done) break;
                shortest_path++;
            }

        }

        return res;
        
    }
};
