class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        map<int,int> in_degree;
        map<int,int> out_degree;
        
        for(int i=1; i<=n; i++) {
            in_degree[i] = 0;
            out_degree[i] = 0;
        }
        
        for(vector<int> edge : trust) {
            out_degree[edge[0]] += 1;
            in_degree[edge[1]] += 1;
        }
        
        for(int i=1; i<=n; i++) {
            if(out_degree[i] == 0 && in_degree[i] == n-1) {
                return i;
            }
        }
        
        return -1;
        
    }
};
