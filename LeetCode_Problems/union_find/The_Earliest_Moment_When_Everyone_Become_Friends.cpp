class Solution {
public:

    static bool compare_log(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }

    class UnionFind {

        public:

        vector<int> rank;
        vector<int> root;
        int num_components;

        UnionFind(int n) {
            for(int i=0; i<n; i++) {
                rank.push_back(0);
                root.push_back(i);
            }

            num_components = n;
        }

        int find(int n) {
            if(root[n] == n) {
                return n;
            }

            return find(root[n]);
        }

        int connect(int node1, int node2) {
            int root1 = find(node1);
            int root2 = find(node2);

            if(root1 == root2) return num_components;

            if(rank[root1] > rank[root2]) {
                root[root2] = root1;
            } else if(rank[root2] > rank[root1]){
                root[root1] = root2;
            } else {
                root[root1] = root2;
                rank[root2] += 1;
            }

            num_components--;

            return num_components;
        }

    };

    int earliestAcq(vector<vector<int>>& logs, int n) {

        sort(logs.begin(), logs.end(), compare_log);

        UnionFind uf(n);

        for(auto &log : logs) {

            int components = uf.connect(log[1], log[2]);

            if(components == 1) return log[0];
        }

        return -1; // Never reached
        
    }
};
