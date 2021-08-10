class Solution {
public:
    
    map<int, int> memo;
    
    int numTrees(int n) {
        
        if(n == 1) return 1;
        if(n == 0) return 1;
        if(memo.find(n) != memo.end()) return memo[n];
        
        int num_unique_trees = 0;
        
        for(int i=0; i<n; i++) {
            num_unique_trees += numTrees(n - i - 1) * numTrees(i);
        }
        
        memo[n] = num_unique_trees;
        
        return num_unique_trees;
        
    }
    
    
};
