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
    
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        
        int sent_size = sentence1.size();
        if(sent_size != sentence2.size()) return false;
        
        map<string, int> string_hash;
        
        int hash_val = 0;
        for(vector<string> s_vec : similarPairs) {
            
            string_hash[s_vec[0]] = hash_val;
            hash_val++;
            
            string_hash[s_vec[1]] = hash_val;
            hash_val++;
        }
        
        UnionFind uf(hash_val);
        
        for(vector<string> s_vec : similarPairs) {
            uf.union_nodes( string_hash[s_vec[0]], string_hash[s_vec[1]] );
        }
        
        for(int i=0; i<sent_size; i++) {
            string word1 = sentence1[i];
            string word2 = sentence2[i];
            
            if(word1 == word2) continue;
            
            if(string_hash.find(word1) == string_hash.end() || string_hash.find(word2) == string_hash.end()) {
                return false;
            }
            
            if( uf.find(string_hash[word1]) != uf.find(string_hash[word2]) ) {
                return false;
            }
            
        }
        
        return true;
    }
};
