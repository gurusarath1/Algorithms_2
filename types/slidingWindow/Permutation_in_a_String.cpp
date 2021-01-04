/*
Given a string and a pattern, find out if the string contains any permutation of the pattern.

Permutation is defined as the re-arranging of the characters of the string. For example, “abc” has the following six permutations:

    abc
    acb
    bac
    bca
    cab
    cba

If a string has ‘n’ distinct characters, it will have n!n!n! permutations.

Input: String="oidbcaf", Pattern="abc"
Output: true
Explanation: The string contains "bca" which is a permutation of the given pattern.

Input: String="odicf", Pattern="dc"
Output: false
Explanation: No permutation of the pattern is present in the given string as a substring.

*/

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class StringPermutation {
 public:
  static bool findPermutation(const string &str, const string &pattern) {
    
    int window_len = pattern.size();
    unordered_map<char, int> char_freqs;
    unordered_map<char, int> char_freqs_in_pattern;
    int start_index = 0, end_index = window_len - 1;
    int match_count;

    if(window_len > str.size()) {
      return false;
    }

    for(int i=0; i<window_len; i++) {

      char_freqs[str[i]] = char_freqs[str[i]] + 1;
      char_freqs_in_pattern[pattern[i]] = char_freqs_in_pattern[pattern[i]] + 1;

    }

    do {

      match_count = 0;
      for(int i=0; i<window_len; i++) {

        if(char_freqs[pattern[i]] == char_freqs_in_pattern[pattern[i]]) {
          match_count++;
        }

      }

      if(match_count == window_len) {
        return true;
      }

      char_freqs[str[start_index]]--;
      start_index++;
      end_index++;
      char_freqs[str[end_index]]++;

    } while(end_index < str.size());



    return false;
  }
};
