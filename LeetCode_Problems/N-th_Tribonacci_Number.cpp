class Solution {
public:
    int tribonacci(int n) {

        int t_0 = 0;
        int t_1 = 1;
        int t_2 = 1;

        if(n == 0) return t_0;
        if(n == 1) return t_1;
        if(n == 2) return t_2;

        for(int i=3; i<=n; i++) {
            int num = t_0 + t_1 + t_2;

            t_0 = t_1;
            t_1 = t_2;
            t_2 = num;
        }
        
        return t_2;
    }
};
