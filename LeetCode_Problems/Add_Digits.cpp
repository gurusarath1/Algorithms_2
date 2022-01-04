class Solution {
public:
    int addDigits(int num) {
        
        int single_digit_sum = num;
        
        do {
            single_digit_sum = digit_sum(single_digit_sum);
        } while(single_digit_sum > 9);
        
        return single_digit_sum;
    }
    
    int digit_sum(int num) {
        int sum = 0;
        while(num != 0) {
            int digit = num % 10;
            num = num / 10;
            sum += digit;
        }
        return sum;
    }
    
};
