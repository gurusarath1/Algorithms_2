class Solution {
public:
    bool isArmstrong(int n) {
        
        int num = n;
        
        int num_digits = 0;
        int digit;
        int sum_of_kth_powers = 0;
        while(num != 0) {
            
            num_digits += 1;
            
            digit = num%10;
            num = num/10;
            
        }
        
        num = n;
        while(num != 0) {
            
            digit = num%10;
            num = num/10;
            sum_of_kth_powers += pow(digit, num_digits);
            
        }
        
        if(sum_of_kth_powers == n) {
            return true;
        } else {
            return false;
        }
    }
};
