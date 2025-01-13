class Solution {
public:
    int minimumLength(string s) {

        unordered_map<char, int> freq;
        for(char c : s) {
            freq[c] += 1;
        }

        int res = 0;
        for(auto p : freq) {
            if(p.second < 3) {
                res += p.second;
            } else {
                if(p.second & 1) {
                    res += 1;
                } else {
                    res += 2;
                }
            }
        }
        
        return res;
    }
};
