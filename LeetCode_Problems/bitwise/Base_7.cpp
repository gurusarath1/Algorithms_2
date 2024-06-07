class Solution {
public:
    string convertToBase7(int num) {
        
        string ret = "";
        
        int n = num;
        
        if(n < 0) {
            n = -n;
        } else if(num == 0) {
            return "0";
        }
        
        while(n > 0) {
            
            if(n % 7 == 0) {
                ret += "0";
            } else {
                char c = (char)('0' + n%7);
                ret.push_back(c);
            }
            
            n = n / 7;
        }
        
        if(num < 0) {
            ret += "-";
        }
        
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};
