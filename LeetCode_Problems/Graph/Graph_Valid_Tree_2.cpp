class Solution {
public:
    
    class UnionFind {
        
        public:
        
        vector<int> root;
        vector<int> rank;
        
        UnionFind(int num_nodes) {
            root.resize(num_nodes);
            rank.resize(num_nodes);
            
            for(int i=0; i<num_nodes; i++) {
                root[i] = i;
                rank[i] = 1;
            }
        }
        
        int find(int node) {
            if(root[node] == node) {
                return node;
            }
            
            return root[node] = find(root[node]);
        }
        
        int connect(int node1, int node2) {
            int root1 = find(node1);
            int root2 = find(node2);
            
            if(root1 == root2) {
                return 0;
            } else {
                if(rank[root1] > rank[root2]) {
                    root[node2] = node1;
                } else if (rank[root1] < rank[root2]) {
                    root[node1] = node2;
                } else {
                    root[node2] = node1;
                    rank[root1] += 1;
                }                
            }
            
            return 1;
        }
        
    };
    
    bool validTree(int n, vector<vector<int>>& edges) {
        
        if(edges.size() > n-1 || edges.size() < n-1) {
            return false;
        }
        
        UnionFind uf(n);
        
        for(vector<int> edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            
            if(!uf.connect(node1, node2)) return false;
        }
        
        return true;
    }
};
