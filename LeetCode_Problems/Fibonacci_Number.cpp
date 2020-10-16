class Solution {
public:
    int fib(int N) {
        
        map<int,int> memo;
        
        return fib_support(N, memo);
        
    }
    
    int fib_support(int N, map<int, int>& memo) {
        
        if(memo[N] != 0) return memo[N];
        
        if(N == 0) return 0;
        if(N == 1) return 1;
        
        int result = fib_support(N-1, memo) + fib_support(N-2, memo);
        memo[N] = result;
        
        return result;
    }
};
