class Solution {
public:
    string addBinary(string a, string b) {
        
        int i = a.size() - 1;
        int j = b.size() - 1;
        string result = "";
        
        int c = 0;
        while(i >= 0 || j >= 0) {
            
            int bit_1 = 0;
            int bit_2 = 0;
            
            if(i >= 0) {
                bit_1 = a[i] - '0';
            }
            
            if(j >= 0) {
                bit_2 = b[j] - '0';
            }
            
            int sum = bit_1 + bit_2 + c;
            
            if(sum == 0) {
                result += "0";
                c = 0;
            } else if(sum == 1) {
                result += "1";
                c = 0;
            } else if(sum == 2) {
                result += "0";
                c = 1;
            } else if(sum == 3) {
                result += "1";
                c = 1;
            }
            
            i--;
            j--;
        }
        
        
        if(c == 1) result += "1";
        
        reverse(result.begin(), result.end());
        
        return result;
        
    }
};
