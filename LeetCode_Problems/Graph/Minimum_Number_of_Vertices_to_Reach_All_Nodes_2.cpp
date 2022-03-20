class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        set<int> not_in_set;
        for(vector<int> edge : edges) {
            not_in_set.insert(edge[1]);
        }
        
        vector<int> result;
        for(int i=0; i<n; i++) {
            if(not_in_set.find(i) == not_in_set.end()) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
