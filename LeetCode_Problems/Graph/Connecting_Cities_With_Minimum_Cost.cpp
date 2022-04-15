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
            
            num_components = n+1;
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
            } else {
                
                if(rank[root1] < rank[root2]) {
                    root[root1] = root2;
                } else if(rank[root1] > rank[root2]) {
                    root[root2] = root1;
                } else {
                    root[root1] = root2;
                    rank[root2]++;
                }
                
            }
            
            num_components--;
            return true;
        }
        
    };
    
    static bool compare(vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    }
    
    int minimumCost(int n, vector<vector<int>>& connections) {
        
        UnionFind uf(n);
        
        sort(connections.begin(), connections.end(), compare);
        
        int weight = 0;
        for(vector<int> edge : connections) {
            
            if(uf.union_nodes(edge[0], edge[1])) {
                weight += edge[2];
            }
            
            if(uf.num_components == 2) {
                return weight;
            }
        }
        
        return -1;
        
    }
};
