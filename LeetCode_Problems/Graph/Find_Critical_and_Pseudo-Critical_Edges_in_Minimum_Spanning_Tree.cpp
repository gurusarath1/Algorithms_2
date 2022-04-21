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
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> result;
        vector<int> critical_edges;
        vector<int> pseudo_critical_edges;
        map<vector<int>, int> edge_index;
        
        vector<vector<int>> edges_sorted = edges;
        sort(edges_sorted.begin(), edges_sorted.end(), compare);
        
        int index = 0;
        for(vector<int> edge : edges) {
            edge_index[edge] = index;
            index++;
        }
        
        
        // Run regular MST on the graph
        int MST_weight = 0; // Weight of MST
        UnionFind uf(n);
        for(vector<int> edge : edges_sorted) {
            if(uf.union_nodes(edge[0], edge[1])) {
                MST_weight += edge[2];
                if(uf.num_components == 1) break;
            }
        }
        
        //---------------------------------------------------------------------------------------
        
        
        // Edge classification
        int new_MST_weight = 0;
        for(vector<int> ignore_edge : edges_sorted) {
            
            UnionFind uf2(n);
            new_MST_weight = 0;
            for(vector<int> edge : edges_sorted) {
                
                // Run MST by skipping this one edge to check it's type
                if(ignore_edge == edge) {
                    continue;
                }
                
                if(uf2.union_nodes(edge[0], edge[1])) {
                    new_MST_weight += edge[2];
                    if(uf2.num_components == 1) break;
                }
            }
            
            // If (ignoring the edge disconnects th graph || increases weight) it is a critical edge
            if(uf2.num_components > 1 || new_MST_weight > MST_weight) {
                // Critical edge
                critical_edges.push_back(edge_index[ignore_edge]);
            } else { //new_MST_weight == MST_weight
                
                // Force include the edge
                UnionFind uf3(n);
                uf3.union_nodes(ignore_edge[0], ignore_edge[1]);
                int new_MST_weight_2 = ignore_edge[2];
                for(vector<int> edge : edges_sorted) {
                    if(ignore_edge == edge) {
                        continue;
                    }

                    if(uf3.union_nodes(edge[0], edge[1])) {
                        new_MST_weight_2 += edge[2];
                        if(uf3.num_components == 1) break;
                    }
                }
                
                if(new_MST_weight_2 == MST_weight) {
                    // psuedo critical edge
                    pseudo_critical_edges.push_back(edge_index[ignore_edge]);
                }
            }

        }
        
        result.push_back(critical_edges);
        result.push_back(pseudo_critical_edges);
        
        return result;
    }
};
