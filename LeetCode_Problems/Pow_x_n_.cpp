class Solution {
public:
    double myPow(double x, int n) {
        
        if(n == 1) return x;
        if(n == 0) return 1;
        
        unsigned long long int power = n;
        
        if(n < 0) {
            power = abs(n);
            x = 1/x;
        }
        
        double result_n_by_2;
        if(power % 2 == 1) {
            power = power - 1;
            result_n_by_2 = myPow(x, power/2);
            return result_n_by_2 * result_n_by_2 * x;
        } else {
            result_n_by_2 = myPow(x, power/2);
            return result_n_by_2 * result_n_by_2;
        }
        
    }
};
