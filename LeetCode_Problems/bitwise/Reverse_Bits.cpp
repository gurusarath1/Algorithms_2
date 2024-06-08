class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        int power = 31;
        uint32_t rev_num = 0;
        while(n != 0)
        {
            int bit = n&1;
            if(bit) rev_num |= (1 << power);

            power--;
            n = n >> 1;
        }

        return rev_num;
    }
};
