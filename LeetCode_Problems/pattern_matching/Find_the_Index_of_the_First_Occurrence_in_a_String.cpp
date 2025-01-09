class Solution {
public:
    int strStr(string haystack, string needle) {

        vector<int> lps(needle.size(), 0);

        int prev_lps = 0;
        int i=1;
        while(i<needle.size()) {
            if(needle[i] == needle[prev_lps]) {
                lps[i] = prev_lps + 1;
                prev_lps += 1;
                i++;
            } else {
                if(prev_lps == 0) {
                    lps[i] = 0;
                    i++;
                } else {
                    prev_lps = lps[prev_lps-1];
                }
            }
        }

        i=0;
        int j=0;
        while(i<haystack.size()) {

            if(haystack[i] == needle[j]) {
                j++;
                i++;
            } else {
                if(j == 0) {
                    i++;
                } else {
                    j = lps[j-1];
                }
            }

            if(j == needle.size()) return i-j;
        }

        return -1;
        
    }
};
