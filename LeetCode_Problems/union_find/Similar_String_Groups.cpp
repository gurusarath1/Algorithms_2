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
            
            if(rank[root1] < rank[root2]) {
                root[root1] = root2;
            } else if(rank[root1] > rank[root2]) {
                root[root2] = root1;
            } else {
                root[root1] = root2;
                rank[root2] += 1;
            }
            
            num_components--;
            
            return true;
        }
        
        
    };
    
    bool are_similar(string s1, string s2) {
        int count = 0;
        
        for(int i=0; i<s1.size(); i++) {
            if(s1[i] != s2[i]) count++;
        }
        
        if(count == 0 || count == 2) {
            return true;
        }
        
        return false;
    }
    
    
    int numSimilarGroups(vector<string>& strs) {
        
        int n = strs.size();
        UnionFind uf(n);
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(are_similar(strs[i] , strs[j])) {
                    uf.union_nodes(i,j);
                }
            }
        }
        
        return uf.num_components;
    }
};
