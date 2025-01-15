class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ans = 0;
        int num_set_bits_in_2 = 0;

        while(num2) {
            num2 &= (num2 - 1);
            num_set_bits_in_2++;
        }

        int bit_pos = 30;
        while(num_set_bits_in_2 && bit_pos >= 0) {
            if( (1 << bit_pos) & num1 ) {
                ans |= (1 << bit_pos);
                num_set_bits_in_2--;
            }
            bit_pos--;
        }

        bit_pos = 0;
        while(num_set_bits_in_2 && bit_pos <= 30) {
            if( !((1 << bit_pos) & num1) ) {
                ans |= (1 << bit_pos);
                num_set_bits_in_2--;
            }
            bit_pos++;
        }

        return ans;
    }
};
