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
            
            num_components = n;
        }
        
        int find(int node) {
            
            if(root[node] == node) {
                return node;
            }
            
            return root[node] = find(root[node]);
        }
        
        int union_nodes(int node1, int node2) {
            
            int root1 = find(node1);
            int root2 = find(node2);
            
            if(root1 != root2) {
                
                if(rank[root1] > rank[root2]) {
                    root[root1] = root2;
                } else if(rank[root1] < rank[root2]) {
                    root[root2] = root1;
                } else {
                    root[root2] = root1;
                    rank[root1] += 1;
                }
                
                num_components--;
                
                return 1;
            }
            
            return 0;
        }
        
        
    };
    
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int total_num_edges = connections.size();
        if(total_num_edges < n-1) { // You need minimum n-1 edges to connect n nodes
            return -1;
        }
        
        UnionFind uf(n);
        
        for(vector<int> edge : connections) {
            uf.union_nodes(edge[0], edge[1]);
        }
        
        int num_components = uf.num_components;
        int num_edges_needed = num_components - 1;
        
        return num_edges_needed;
    }
};
