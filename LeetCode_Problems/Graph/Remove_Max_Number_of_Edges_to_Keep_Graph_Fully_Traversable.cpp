class Solution {
public:
    
    class UnionFind {
        public:
        vector<int> root;
        vector<int> rank;
        int num_components;
        UnionFind(int n) {
            for(int i=0; i<=n; i++) {
                root.push_back(i);
                rank.push_back(1);
            }
            
            num_components = n;
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
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        int num_edges = edges.size();
        UnionFind uf_common(n);
        
        vector<vector<int>> common_edges;
        vector<vector<int>> a_edges;
        vector<vector<int>> b_edges;
        
        for(vector<int> edge : edges) {
            if(edge[0] == 3) {
                common_edges.push_back( {edge[1], edge[2]} );
            } else if(edge[0] == 2) {
                a_edges.push_back( {edge[1], edge[2]} );
            } else {
                b_edges.push_back( {edge[1], edge[2]} );
            }
        }
        
        int num_edges_needed = 0;
        for(vector<int> common_edge : common_edges) {
            if(uf_common.union_nodes(common_edge[0], common_edge[1])) {
                num_edges_needed++;
            }
        }
        
        if(uf_common.num_components == 1) return num_edges - num_edges_needed;
        
        UnionFind uf_a = uf_common;
        for(vector<int> a_edge : a_edges) {
            if(uf_a.union_nodes(a_edge[0], a_edge[1])) {
                num_edges_needed++;
            }
        }
        
        if(uf_a.num_components > 1) return -1;
        
        UnionFind uf_b = uf_common;
        for(vector<int> b_edge : b_edges) {
            if(uf_b.union_nodes(b_edge[0], b_edge[1])) {
                num_edges_needed++;
            }
        }

        if(uf_b.num_components > 1) return -1;
        
        return num_edges - num_edges_needed; 
    }
};
