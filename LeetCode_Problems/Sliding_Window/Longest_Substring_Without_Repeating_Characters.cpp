class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char, int> chars_in_window_count;
        int start_index = 0;
        int max_len = 0;
        
        for(int end_index = 0; end_index < s.size(); end_index++) {
            
            chars_in_window_count[s[end_index]] += 1;
            
            while(chars_in_window_count[s[end_index]] > 1) {
                chars_in_window_count[s[start_index]] -= 1;
                start_index++;
            }
            
            max_len = max(max_len, end_index - start_index + 1);
            
        }
        
        return max_len;
        
    }
};
