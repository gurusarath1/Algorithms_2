class Solution {
public:
    
    class UnionFind {
        
    public:
        vector<int> roots;
        vector<int> rank;
        int num_components;
        
        UnionFind(int num_nodes) {
            roots.resize(num_nodes);
            rank.resize(num_nodes);
            
            for(int i=0; i<num_nodes; i++) {
                roots[i] = i;
                rank[i] = 1;
            }
            
            num_components = num_nodes;
            
        }
        
        int find(int node) {
            
            if(roots[node] == node) {
                return node;
            }
            
            return roots[node] = find(roots[node]);
            
        }
        
        
        void union_set(int node_1, int node_2) {
            int root_1 = find(node_1);
            int root_2 = find(node_2);
            
            if(root_1 != root_2) {
                
                if(rank[root_1] > rank[root_2]) {
                    roots[root_1] = root_2;
                } else if(rank[root_1] < rank[root_2]) {
                    roots[root_2] = root_1;
                } else {
                    roots[root_2] = root_1;
                    rank[root_1] += 1;
                }
                
                num_components--;
            }
            
        }
        
        bool is_connected(int node_1, int node_2) {
            return find(node_1) == find(node_2);
        }
    };
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        UnionFind uf(grid.size() * grid[0].size());
        
        int max_row_index = grid.size() - 1;
        int max_col_index = grid[0].size() - 1;
        int num_zeros = 0;
        for(int i=0; i<grid.size(); i++) {
            
            for(int j=0; j<grid[0].size(); j++) {
                
                if(grid[i][j] == '1') {
                    
                    grid[i][j] = '0';
                    if(i+1 <= max_row_index && grid[i+1][j] == '1') {
                        uf.union_set( i*(max_col_index+1) + j, (i+1)*(max_col_index+1) + j );
                    }
                    if(i-1 >= 0 && grid[i-1][j] == '1') {
                        uf.union_set( i*(max_col_index+1) + j, (i-1)*(max_col_index+1) + j );
                    }
                    if(j-1 >= 0 && grid[i][j-1] == '1') {
                        uf.union_set( i*(max_col_index+1) + j, i*(max_col_index+1) + (j-1) );
                    }
                    if(j+1 <= max_col_index && grid[i][j+1] == '1') {
                        uf.union_set( i*(max_col_index+1) + j, i*(max_col_index+1) + (j+1) );
                    }
                     
                } else {
                    num_zeros++;
                }
                
            }
            
        }
        
        return uf.num_components - num_zeros;
        
    }
};
