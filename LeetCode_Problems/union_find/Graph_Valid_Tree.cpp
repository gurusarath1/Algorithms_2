class Solution {
public:
    class unionFind{
        
        vector<int> nodes;
        
        public:
        
        unionFind(int num_nodes) {
            nodes.resize(num_nodes);
            for(int i=0; i<nodes.size(); i++) {
                nodes[i] = i;
            }
        }
        
        int find(int node) {
            
            while(node != nodes[node]) {
                node = nodes[node];
            }
            
            return node;
        }
        
        int quick_union(int node1, int node2) {
            int root1 = find(node1);
            int root2 = find(node2);
            
            if(root1 != root2) {
                nodes[root1] = root2;
            } else {
                return 0;
            }
            
            return 1;
        }
        
    };
    
    bool validTree(int n, vector<vector<int>>& edges) {
        
        unionFind uf(n);
        
        for(vector<int> edge : edges) {
            if(uf.quick_union(edge[0], edge[1])) {
                ;
            } else {
                return false;
            }
        }
        
        set<int> unique_roots;
        
        for(int i=0; i<n; i++) {
            unique_roots.insert(uf.find(i));
        }
        
        if(unique_roots.size() > 1) return false;
        
        return true;

    }
};
