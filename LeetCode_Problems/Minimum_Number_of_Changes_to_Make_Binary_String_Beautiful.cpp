class Solution {
public:
    int minChanges(string s) {

        int count = 0;
        for(int i=0; i<s.size(); i+=2) {
            int diff = s[i] + s[i+1] - '0' - '0';

            if(diff == 1) count++;
        }

        return count;
    }
};
