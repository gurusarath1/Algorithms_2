class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        vector<int> max_char_counts_words2(26, 0);
        unordered_set<char> unique_chars_words2;
        vector<string> res;

        for(string &s : words2) {
            vector<int> num_char_counts_s(26, 0);
            for(char c : s) {
                num_char_counts_s[c - 'a'] += 1;
                unique_chars_words2.insert(c);
            }
            for(char c : s) {
                if(num_char_counts_s[c - 'a'] > max_char_counts_words2[c - 'a']) {
                    max_char_counts_words2[c - 'a'] = num_char_counts_s[c - 'a'];
                }
            }
        }

        for(string &a : words1) {
            vector<int> num_char_counts_a(26, 0);
            for(char c : a) {
                num_char_counts_a[c - 'a'] += 1;
            }

            bool is_universal = true;
            for(char c : unique_chars_words2) {
                if(num_char_counts_a[c - 'a'] < max_char_counts_words2[c - 'a']) {
                    is_universal = false;
                    break;
                }
            }

            if(is_universal) {
                res.push_back(a);
            }
        }

        return res;
    }
};
