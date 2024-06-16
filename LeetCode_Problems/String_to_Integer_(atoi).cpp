class Solution {
public:
    int myAtoi(string s) {

        bool is_negative = false;

        int idx = 0;
        while(s[idx] == ' ') idx++;

        if(s[idx] == '-' || s[idx] == '+') {
            if(s[idx] == '-') is_negative = true;
            idx++;
        }

        long long val = 0;
        for(;idx<s.size(); idx++) {

            if(s[idx] <= '9' && s[idx] >= '0') {
                int digit = s[idx] - '0';
                val = val*10;
                val += digit;

                if(is_negative && -val < INT_MIN) return INT_MIN;
                if(!is_negative && val > INT_MAX) return INT_MAX;
    
            } else  {
                break;
            }

        }

        if(is_negative) {
            val = -val;
        }

        return val;
    }
};
