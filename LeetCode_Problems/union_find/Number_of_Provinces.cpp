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
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        unionFind uf(isConnected.size());
        
        for(int i=0; i<isConnected.size(); i++) {
            for(int j=0; j<isConnected[0].size(); j++) {
                if(i != j && isConnected[i][j]) {
                    uf.quick_union(i, j);
                }
            }
        }
        
        set<int> unique_parents;
        
        for(int i=0; i<isConnected.size(); i++) {
            int rootX = uf.find(i);
            unique_parents.insert(rootX);
        }
        
        return unique_parents.size();
    }
};
