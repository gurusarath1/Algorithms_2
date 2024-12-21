class Solution {
public:

    int num_components = 0;

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {

        map<int, vector<int>> g;

        for(vector<int> &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        get_num_k_div_greedy_splits(g, values, 0, -1, k);
        
        return num_components;
    }

    long long get_num_k_div_greedy_splits(map<int, vector<int>>& g, vector<int>& values, int current_node, int parent_node, int k) {

        long long sum = values[current_node];

        for(int next_node : g[current_node]) {
            if(next_node != parent_node) {
                sum += get_num_k_div_greedy_splits(g, values, next_node, current_node, k);
            }
        }

        if(sum%k == 0) {
            num_components++;
            return 0;
        }

        return sum;
    }
};
