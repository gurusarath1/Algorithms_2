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
        
        bool union_nodes(int node1, int node2) {
            int root1 = find(node1);
            int root2 = find(node2);
            
            if(root1 == root2) {
                return false;
            }
            
            if(rank[root1] > rank[root2]) {
                root[root2] = root1;
            } else if(rank[root1] < rank[root2]) {
                root[root1] = root2;
            } else {
                root[root1] = root2;
                rank[root2] += 1;
            }
            
            num_components--;
            return true;
        }
        
    };
    
    static bool compare(vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    }
    
    
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        
        int min_cost = 0;
        
        
        // Add more edges to consider cost of building wells
        for(int i=1; i<=n; i++) {
            pipes.push_back( {0, i, wells[i-1]} );
        }
        
        sort(pipes.begin(), pipes.end(), compare);
        
        UnionFind uf(n+1);
        for(vector<int> edge : pipes) {
            if(uf.union_nodes(edge[0], edge[1])) {
                min_cost += edge[2];
            }
        }
        

        return min_cost;
        
    }
};
