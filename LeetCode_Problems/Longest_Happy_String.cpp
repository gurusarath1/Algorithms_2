class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ret = "";
        int a_chain = 0, b_chain = 0, c_chain = 0;
        while(1) {

            char turn = get_turn(a,b,c,a_chain,b_chain,c_chain);

            if(turn == 'a') {
                ret += 'a';
                a--;
                a_chain += 1;
                b_chain = 0;
                c_chain = 0;
            } else if(turn == 'b') {
                ret += 'b';
                b--;
                a_chain = 0;
                b_chain += 1;
                c_chain = 0;
            } else if(turn == 'c') {
                ret += 'c';
                c--;
                a_chain = 0;
                b_chain = 0;
                c_chain += 1;
            } else {
                break;
            }

        }

        return ret;
    }

    char get_turn(int a, int b, int c, int a_chain, int b_chain, int c_chain) {

        if(a_chain >= 2) {
            a = 0;
        } else if(b_chain >= 2) {
            b = 0;
        } else if(c_chain >= 2) {
            c = 0;
        }

        if(a && a >= b && a >= c && a_chain < 2) {
            return 'a';
        } else if(b && b >= a && b >= c && b_chain < 2) {
            return 'b';
        } else if(c && c >= a && c >= b && c_chain < 2) {
            return 'c';
        }
        return '0';
    }
};
