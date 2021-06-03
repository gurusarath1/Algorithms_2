class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        int start_index = 0;
        int num_distinct_chars = 0;
        set<char> chars_in_window;
        map<char,int> chars_in_window_count; 
        int max_substring_size = 0;
        
        
        for(int end_index=0; end_index < s.size(); end_index++) {
            
            chars_in_window.insert(s[end_index]);
            chars_in_window_count[s[end_index]] = chars_in_window_count[s[end_index]] + 1;
            num_distinct_chars = chars_in_window.size();
            
            while(num_distinct_chars > k) {
                
                char c = s[start_index];
                chars_in_window_count[c] -= 1;
                start_index++;
                
                if(chars_in_window_count[c] == 0) {
                    chars_in_window.erase(c);
                    num_distinct_chars = chars_in_window.size();
                }
            }
            
            max_substring_size = max(max_substring_size, end_index - start_index + 1);
            
        }
        
        return max_substring_size;
        
    }
};
