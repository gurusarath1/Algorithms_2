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
            }
            return 1;
        }
        
    };
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        unionFind uf(n+1);
        
        for(vector<int> edge : edges) {
            uf.quick_union(edge[0], edge[1]);
        }
        
        if(uf.find(source) == uf.find(destination)) {
            return true;
        }
        
        return false;
    }
};
