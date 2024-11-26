class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_set<int> result_nodes;

        for(int i=0; i<n; i++) {
            result_nodes.insert(i);
        }

        for(vector<int> &edge : edges) {
            result_nodes.erase(edge[1]);
        }

        if(result_nodes.size() == 1) {
            return *result_nodes.begin();
        }

        if(result_nodes.size() == 0 && n == 1) {
            return 0;
        }

        return -1;
    }
};
