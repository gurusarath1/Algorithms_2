class Solution {
public:

    bool is_aeiou(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        vector<int> prefix_sum(words.size(), 0);
        vector<int> res(queries.size());

        for(int i=0; i<words.size(); i++) {
            if(i != 0) prefix_sum[i] += prefix_sum[i - 1];
            if(is_aeiou(words[i][0]) && is_aeiou(words[i][words[i].size()-1])) {
                prefix_sum[i] += 1;
            }
        }

        int i=0;
        for(vector<int>&q : queries) {
            int res_i;
            if(q[0]-1 >= 0) res_i = prefix_sum[q[1]] - prefix_sum[q[0]-1];
            else res_i = prefix_sum[q[1]];
            res[i++] = res_i;
        }

        return res;
        
    }
};
