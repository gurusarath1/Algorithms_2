class Solution {
public:
    
    class UnionFind {
        
        public:
        vector<int> root;
        vector<int> rank;
        int num_components;
        UnionFind(int n) {
            for(int i=0; i<n; i++) {
                root.push_back(i);
                rank.push_back(1);
            }
            num_components = n-1;
        }
        
        int find(int node) {
            if(node == root[node]) {
                return node;
            }
            
            return root[node] = find(root[node]);
        }
        
        bool union_nodes(int node1, int node2) {
            int root1 = find(node1);
            int root2 = find(node2);
            
            if(root1 == root2) {
                return false;
            } else {
                
                if(rank[root1] > rank[root2]) {
                    root[root2] = root1;
                } else if(rank[root1] < rank[root2]) {
                    root[root1] = root2;
                } else {
                    root[root1] = root2;
                    rank[root2] += 1;
                }
                
            }
            
            num_components--;
            return true;
        }
        
    };
    
    vector<int> hasCycle(int n, vector<vector<int>> &edges, vector<int> &skip_edge, int &num_components) {
        UnionFind uf(n+1);
        
        for(vector<int> edge : edges) {
            
            if(edge == skip_edge) {
                continue;
            }
            
            //cout << "Before next\n";
            if(!uf.union_nodes(edge[0], edge[1])) {
                num_components = uf.num_components;
                return edge;
            }
        }
        
        num_components = uf.num_components;
        
        return skip_edge;
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        
        int root;
        map<int, vector<int>> in_degree;
        int node_with_in_degree_2;
        vector<int> edge_with_degree_2(2,-1);
        bool degree_2_node_is_present = false;
        int n = 0;
        
        for(vector<int> edge : edges) {
            in_degree[edge[1]].push_back(edge[0]);
            
            if(in_degree[edge[1]].size() > 1) {
                node_with_in_degree_2 = edge[1];
                degree_2_node_is_present = true;
            }
            
            if(n < edge[0]) n = edge[0];
            if(n < edge[1]) n = edge[1];
        }
        
        if(degree_2_node_is_present) {
            
            int num_components;
            
            // One of the two edges must be removed
            vector<int> edge_1 = { in_degree[node_with_in_degree_2][0], node_with_in_degree_2 };
            vector<int> edge_2 = { in_degree[node_with_in_degree_2][1], node_with_in_degree_2 };
            
            // If excluding the second edge (later edge) does not disconnect the graph then return second edge else return first edge
            hasCycle(n, edges, edge_2, num_components);

            if(num_components == 1) {
                return edge_2;
            } else {
                return edge_1;
            }
            
            
        } else {
            // Just get the edge that forms a cycle
            int num_components_unused;
            vector<int> skip_no_edge = {-1,-1};
            return hasCycle(n, edges, skip_no_edge, num_components_unused);
        }
        
        return {-1,-1};
    }
};
