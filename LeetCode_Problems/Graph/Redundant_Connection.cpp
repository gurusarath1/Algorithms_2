class Solution {
public:
    
    class UnionFind {
        public:
        
        vector<int> root;
        vector<int> rank;
        
        UnionFind(int n) {
            
            for(int i=0; i<n; i++) {
                root.push_back(i);
                rank.push_back(1);
            }
        }
        
        int find(int node) {
            
            if(root[node] == node) {
                return root[node];
            }
            
            return root[node] = find(root[node]);
        }
        
        int connect(int node1, int node2) {
            
            int root1 = find(node1);
            int root2 = find(node2);
            
            if(root1  == root2) {
                return 0;
            } else {
                if(rank[root1] > rank[root2]) {
                    root[root2] = root1;
                } else if(rank[root1] > rank[root2]) {
                    root[root1] = root2;
                } else {
                    root[root2] = root1;
                    rank[root1] += 1;
                }
            }
            
            return 1;
            
        }
    };
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(1001);
        
        for(vector<int> edge : edges) {
            if(!uf.connect(edge[0], edge[1])) {
                return edge;
            }
        }
        
        return {}; // dummy
        
    }
};
