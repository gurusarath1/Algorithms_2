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
            }
            
            if(rank[root1] > rank[root2]) {
                root[root2] = root1;
            } else if(rank[root1] < rank[root2]) {
                root[root1] = root2;
            } else {
                root[root1] = root2;
                rank[root2] += 1;
            }
            
            return true;
        }
        
    };
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        string return_string = s;
        int n = s.size();
        UnionFind uf(n);
        
        for(vector<int> p : pairs) {
            uf.union_nodes(p[0], p[1]);
        }
        
        
        map<int, vector<int> > root_index_map;
        map<int, vector<char> > root_char_map;
        
        for(int i=0; i<n; i++) {
            int root = uf.find(i);
            root_index_map[root].push_back( i );
            root_char_map[root].push_back( s[i] );
        }
        
        
        for(auto p : root_char_map) {
            int root = p.first;
            
            sort(p.second.begin(), p.second.end());
            
            int i = 0;
            for(char c : p.second) {
                return_string[ root_index_map[root][i] ] = c;
                i++;
            }
            
        }
        
        return return_string;
    }
};
