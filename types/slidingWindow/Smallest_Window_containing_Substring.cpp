using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

class MinimumWindowSubstring {
 public:
  static string findSubstring(const string &str, const string &pattern) {
    // TODO: Write your code here
    cout << "-----------------\n";
    unordered_map<char, int> pattern_freq;
    unordered_map<char, int> window_freq;

    set<char> pattern_char_set;

    for(char c : pattern) {
      pattern_char_set.insert(c);
      pattern_freq[c] += 1;
    }

    int start_index = 0;
    int win_window_size = 999999;
    int min_start, min_end;
    bool found = false;

    for(int end_index = 0; end_index < str.size(); end_index++) {

      cout << "Iteration - " << start_index << "  " << end_index << endl;

      if(pattern_char_set.find(str[end_index]) != pattern_char_set.end()) {
        cout << str[end_index] << " ifone\n";
        window_freq[str[end_index]] = window_freq[str[end_index]] + 1;
      }

      if(window_freq.size() == pattern_freq.size()) {

        cout << "match\n";

        found = true;
        
        while(window_freq.size() == pattern_freq.size()) {
          if(pattern_char_set.find(str[start_index]) != pattern_char_set.end()) {
            if(pattern_freq[str[start_index]] <  window_freq[str[start_index]]) {
              window_freq[str[start_index]] = window_freq[str[start_index]] - 1;
            } else {
              break;
            }
          }
          start_index++;
        }

        cout << start_index << "  " << end_index << endl;

        if(end_index - start_index + 1 < win_window_size) {

          cout << "Min Update\n";
          win_window_size = end_index - start_index + 1;
          min_start = start_index;
          min_end = end_index;
        }

        cout << "match END\n";
      }

    }

    cout << win_window_size << "      " << min_start << "     " << min_end <<endl;

    if(!found) return "";

    return str.substr(min_start, min_end - min_start + 1);
  }
};
