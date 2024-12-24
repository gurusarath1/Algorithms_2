class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        
        unordered_map<int, vector<int>> g1;
        unordered_map<int, vector<int>> g2;

        for(vector<int> &e : edges1) {
            g1[e[0]].push_back(e[1]);
            g1[e[1]].push_back(e[0]);
        }

        for(vector<int> &e : edges2) {
            g2[e[0]].push_back(e[1]);
            g2[e[1]].push_back(e[0]);
        }

        int dia1 = find_diameter_of_tree(g1);
        int dia2 = find_diameter_of_tree(g2);

        return max(max(dia1, dia2), ((dia1+1)/2)+((dia2+1)/2)+1);
    }

    int find_diameter_of_tree(unordered_map<int, vector<int>> &g) {

        int random_start_node = 0;
        queue<int> q;
        set<int> visited;
        q.push(random_start_node);

        int one_end_of_dia = -10000;
        while(!q.empty()) {
            int level_size = q.size();

            for(int i=0; i<level_size; i++) {
                int current_node = q.front();
                q.pop();
                one_end_of_dia = current_node;
                visited.insert(current_node);

                for(int next_node : g[current_node]) {
                    if(visited.find(next_node) == visited.end()) {
                        q.push(next_node);
                    }
                }
            }
        }

        queue<int> qq;
        visited.clear();

        qq.push(one_end_of_dia);
        int other_end_of_dia = -10000;
        int num_hops = -1;
        while(!qq.empty()) {
            int level_size = qq.size();
            num_hops++;

            for(int i=0; i<level_size; i++) {
                int current_node = qq.front();
                qq.pop();
                other_end_of_dia = current_node;
                visited.insert(current_node);

                for(int next_node : g[current_node]) {
                    if(visited.find(next_node) == visited.end()) {
                        qq.push(next_node);
                    }
                }
            }
        }

        return num_hops;

    }

};
