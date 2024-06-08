class Solution {
public:
    string toHex(int num) {
        return base10_to_base16(num);
    }
    
    
    char get_hex_char(unsigned int num) {

        switch(num) {
            case 0:
                return '0';
            case 1:
                return '1';
            case 2:
                return '2';
            case 3:
                return '3';
            case 4:
                return '4';
            case 5:
                return '5';
            case 6:
                return '6';
            case 7:
                return '7';
            case 8:
                return '8';
            case 9:
                return '9';
            case 10:
                return 'a';
            case 11:
                return 'b';
            case 12:
                return 'c';
            case 13:
                return 'd';
            case 14:
                return 'e';
            case 15:
                return 'f';
            default:
                return 0;
                
        }
        
        return 0;
        
    }
    
    
    string base10_to_base16(unsigned int num) {
        unsigned int n = num;
        
        if(n == 0) return "0";
        
        string ret = "";
        
        while(n > 0) {
            unsigned int rem = n%16;
            char c = get_hex_char(rem);
            ret += c;
            n = n/16;
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
    
};
