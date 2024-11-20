
class Solution {
public:

    bool is_valid_window(map<char,int> &counts, int k) {
        if(counts['a'] >= k && counts['b'] >= k && counts['c'] >= k) {
            return true;
        }

        return false;
    }


    int takeCharacters(string s, int k) {

        map<char, int> counts;
        counts['a'] = 0;
        counts['b'] = 0;
        counts['c'] = 0;
        for(char c : s) {
            counts[c] += 1;
        }

        if(!is_valid_window(counts, k)) {
            return -1;
        }

        int max_window_len = 0;
        int left = 0, right = 0;
        while(left <= right && right < s.size() ) {

            counts[s[right]] -= 1;
            bool valid = is_valid_window(counts, k);
            right++;

            if(valid) {
                int window_len = right - left;
                max_window_len = max(max_window_len, window_len);
                continue;
            } else {
                counts[s[left]] += 1;
                left++;
            }
        }

        return s.size() - max_window_len;        
    }
};
