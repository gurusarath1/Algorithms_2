class Solution {
public:

    class unionFind{
        
        #define ALREADY_UNIONED 1
        #define NEW_UNIONED 0
        
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
                return ALREADY_UNIONED;
            }
            
            return NEW_UNIONED;
        }
        
    };
    
    static bool comp_time(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }

    int earliestAcq(vector<vector<int>>& logs, int n) {
        
        unionFind uf(n);
        
        sort(logs.begin(), logs.end(), comp_time);
        
        int num_groups = n;
        
        for(vector<int> log:logs) {
            int person1 = log[1];
            int person2 = log[2];
            
            int already_unioned_flag = uf.quick_union(person1, person2);
            
            if(already_unioned_flag == NEW_UNIONED) {
                num_groups--;
            }
            
            if(num_groups == 1) return log[0];
        }
        
        return -1;
        
    }
};
