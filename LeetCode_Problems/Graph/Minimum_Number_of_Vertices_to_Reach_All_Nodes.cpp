class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        set<int> not_in_min_set;
        set<int> may_be_in_min_set;
        vector<int> min_set;
        
        for(vector<int> edge : edges) {
            not_in_min_set.insert(edge[1]);
            may_be_in_min_set.insert(edge[0]);
        }
        
        for(int node : not_in_min_set) {
            may_be_in_min_set.erase(node);
        }
        
        for(int node : may_be_in_min_set) {
            min_set.push_back(node);
        }
        
        
        return min_set;
    }
};
