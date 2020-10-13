class Solution {
public:
    
    int climbStairs(int n) {
        
        map<int,int> memo;
        return climbStairs_support(n, memo);

    }
    
    int climbStairs_support(int n, map<int, int>& memo) {
        
        if( memo[n] != 0 ) {
            return memo[n];
        }
        
        if(n == 0) {
            return 1;
        }
        
        if(n < 0) {
            return 0;
        }
        
        int numsteps = climbStairs_support(n - 1, memo) + climbStairs_support(n - 2, memo);
        memo[n] = numsteps;
        return numsteps;
             
    }
};
