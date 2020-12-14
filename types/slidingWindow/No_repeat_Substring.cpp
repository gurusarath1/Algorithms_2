/*
Given a string, find the length of the longest substring, which has no repeating characters.
*/

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class NoRepeatSubstring {
 public:
  static int findLength(const string& str) {
    int maxLength = 0;
    int start_index = 0;
    int end_index = 0;
    unordered_map<char, int> chat_freq;
    
    for(end_index=0; end_index < str.size(); end_index++) {

      chat_freq[str[end_index]] = chat_freq[str[end_index]] + 1;

      while(chat_freq[str[end_index]] > 1) {

        if(chat_freq.size() > maxLength) {
          maxLength = chat_freq.size();
        }

        start_index += 1;
        chat_freq[str[start_index]] -= 1;

        if(chat_freq[str[start_index]] == 0) {
          chat_freq.erase(str[start_index]);
        }
      }
    }
    
    return maxLength;
  }
};
