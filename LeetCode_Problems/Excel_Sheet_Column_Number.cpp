class Solution {
public:
    int titleToNumber(string columnTitle) {

        int base = 26;
        int power = 0;
        int ans = 0;
        for(int i=columnTitle.size()-1; i>=0; i--) {
            ans += pow(base, power) * (columnTitle[i] - 'A' + 1);
            power++;
        }
        
        return ans;
    }
};
