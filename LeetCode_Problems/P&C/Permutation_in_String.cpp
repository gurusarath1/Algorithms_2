class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        vector<int> char_freq(26, 0);

        for(char c : s1) {
            char_freq[c - 'a'] += 1;
        }

        for(int i=0; i<s2.size(); i++) {
            vector<int> char_freq_temp = char_freq;
            int num_found = 0;
            for(int j=i; j<s2.size(); j++) {
                int c = s2[j] - 'a';

                if(char_freq_temp[c]) {
                    char_freq_temp[c]--;
                    num_found++;
                } else {
                    break;
                }

                if(num_found == s1.size()) return true;

            }
        }

        return false;
        
    }
};
