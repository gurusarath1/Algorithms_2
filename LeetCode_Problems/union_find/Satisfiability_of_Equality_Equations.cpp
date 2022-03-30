class Solution {
public:
    
    class UnionFind {
        public:
        vector<int> root;
        vector<int> rank;
        
        UnionFind(int n) {
            for(int i=0; i<n; i++) {
                root.push_back(i);
                rank.push_back(i);
            }
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
            } else {
                
                if(rank[root1] > rank[root2]) {
                    root[root2] = root1;
                } else if(rank[root1] < rank[root2]) {
                    root[root1] = root2;
                } else {
                    root[root1] = root2;
                    rank[root2] += 1;
                }
                
            }
            
            return true;
        }
        
    };
    
    bool equationsPossible(vector<string>& equations) {
        
        int num_vars = 0;
        map<char, int> char_to_int;
        
        for(string s : equations) {
            char var1 = s[0];
            char var2 = s[s.size() - 1];
            
            if(char_to_int.find(var1) == char_to_int.end()) {
                char_to_int[var1] = num_vars;
                num_vars++;
            }
            
            if(char_to_int.find(var2) == char_to_int.end()) {
                char_to_int[var2] = num_vars;
                num_vars++;
            }
        }
        
        num_vars++;
        
        UnionFind uf(num_vars);
        
        for(string s : equations) {
            char var1 = s[0];
            char var2 = s[s.size() - 1];
            
            if(s[1] == '=') {
                uf.union_nodes(char_to_int[var1], char_to_int[var2]);
            }
        }
        
        for(string s : equations) {
            char var1 = s[0];
            char var2 = s[s.size() - 1];
            
            if(s[1] == '!' && uf.find(char_to_int[var1]) == uf.find(char_to_int[var2])) {
                return false;
            }
        }
        
        return true;
    }
};
