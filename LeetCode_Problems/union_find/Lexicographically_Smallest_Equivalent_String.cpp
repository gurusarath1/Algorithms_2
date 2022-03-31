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
                
                // Min Node always becomes the root node
                int min_node = min(min(min(node1, node2), root1), root2);
                root[node1] = min_node;
                root[node2] = min_node;
                root[root1] = min_node;
                root[root2] = min_node;
            }
            
            return true;
        }
        
    };
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        int str_size = s1.size();
        
        UnionFind uf('z' - 'a' + 1);
        
        for(int i=0; i<str_size; i++) {
            uf.union_nodes(s1[i] - 'a', s2[i] - 'a');
        }
        
        string ansStr = "";
        
        for(char c : baseStr) {
            
            ansStr += (char)uf.find(c - 'a') + 'a';
        }
        
        return ansStr;
    }
};
