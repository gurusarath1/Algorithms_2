class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int num_flips = 0;
        while(a || b || c) {

            int bit1 = a&1;
            int bit2 = b&1;
            int bit3 = c&1;

            int ored = bit1 | bit2;

            if(ored != bit3) {
                if(bit3 == 0) {
                    if(bit1 == 1 && bit2 == 1) {
                        num_flips += 2;
                    } else {
                        num_flips += 1;
                    }
                } else {
                    num_flips += 1;
                }
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return num_flips;

    }
};
