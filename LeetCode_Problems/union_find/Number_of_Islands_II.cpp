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
            }
            
            if(rank[root1] > rank[root2]) {
                root[root2] = root1;
            } else if (rank[root1] < rank[root2]) {
                root[root1] = root2;
            } else {
                root[root1] = root2;
                rank[root2] += 1;
            }
            num_components--;
            return true;
        }
        
    };
    
    
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int num = m * n;
        UnionFind uf(num);
        vector<int> result;
        
        set<int> lands;
        
        for(int i=0; i<positions.size(); i++) {
            
            int r = positions[i][0];
            int c = positions[i][1];
            
            int new_land = (r * n)+ c;
            lands.insert(new_land);
            int adj_land;
            if(r+1 < m) {
                adj_land = ((r+1) * n) + c;
                if(lands.find(adj_land) != lands.end()) {
                    uf.union_nodes(new_land, adj_land);
                }
            }
            
            if(r-1 >= 0) {
                adj_land = ((r-1) * n) + c;
                if(lands.find(adj_land) != lands.end()) {
                    uf.union_nodes(new_land, adj_land);
                }
            }
            
            if(c+1 < n) {
                adj_land = (r * n) + (c+1);
                if(lands.find(adj_land) != lands.end()) {
                    uf.union_nodes(new_land, adj_land);
                }
            }
            
            if(c-1 >= 0) {
                adj_land = (r * n) + (c-1);
                if(lands.find(adj_land) != lands.end()) {
                    uf.union_nodes(new_land, adj_land);
                }
            }
            
            result.push_back(lands.size() - (num - uf.num_components));
        }
        
        return result;
    }
};
