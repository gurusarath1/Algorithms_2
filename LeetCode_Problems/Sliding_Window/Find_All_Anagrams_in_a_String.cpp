class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        set<char> chars_in_window;
        map<char, int> chars_count_in_window;

        set<char> chars_in_p;
        map<char, int> chars_count_in_p;
        
        for(int i=0; i<p.size(); i++) {
            chars_in_p.insert(p[i]);
            chars_count_in_p[p[i]] += 1;
        }
        
        int window_size = p.size();
        int start = 0;
        vector<int> result;
        for(int i=0; i<s.size(); i++) {
            
            if(i < window_size) {
                
                chars_in_window.insert(s[i]);
                chars_count_in_window[s[i]] += 1;                
                
                if(i == window_size - 1) {
                    if(chars_in_window == chars_in_p && chars_count_in_window == chars_count_in_p) result.push_back(i - window_size + 1);
                }
  
            } else {
                
                chars_in_window.insert(s[i]);
                chars_count_in_window[s[i]] += 1;
                
                if(chars_count_in_window[s[start]] == 1) {
                    chars_count_in_window.erase(s[start]);
                    chars_in_window.erase(s[start]);
                } else {
                    chars_count_in_window[s[start]] -= 1;
                }
                
                start++;
                
                if(chars_in_window == chars_in_p && chars_count_in_window == chars_count_in_p) result.push_back(i - window_size + 1);
                
            }
            
        }
        
        return result;
    }
};
