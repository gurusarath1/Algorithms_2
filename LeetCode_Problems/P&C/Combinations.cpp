class Solution {
public:
    
    vector<vector<int>> result;
    
    vector<vector<int>> combine(int n, int k) {
        
        recurse(n, k, 1, vector<int>{});
        
        return result;
        
    }
    
    void recurse(int n, int k, int current_num, vector<int> picks) {
        
        if(picks.size() == k) {
            result.push_back(picks);
            return;
        }
        
        for(int i=current_num; i<=n; i++) {
            picks.push_back(i);
            recurse(n, k, i+1, picks);
            picks.pop_back();
        }

    }
};
