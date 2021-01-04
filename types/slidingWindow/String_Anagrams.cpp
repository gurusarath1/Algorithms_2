/*

Given a string and a pattern, find all anagrams of the pattern in the given string.

Anagram is actually a Permutation of a string. For example, “abc” has the following six anagrams:

    abc
    acb
    bac
    bca
    cab
    cba

Write a function to return a list of starting indices of the anagrams of the pattern in the given string.


Input: String="ppqp", Pattern="pq"
Output: [1, 2]
Explanation: The two anagrams of the pattern in the given string are "pq" and "qp".

Input: String="abbcabc", Pattern="abc"
Output: [2, 3, 4]
Explanation: The three anagrams of the pattern in the given string are "bca", "cab", and "abc".

*/


using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class StringAnagrams {
 public:
  static vector<int> findStringAnagrams(const string &str, const string &pattern) {
    vector<int> resultIndices;
    int window_len = pattern.size();
    unordered_map<char, int> char_freqs;
    unordered_map<char, int> char_freqs_in_pattern;
    int start_index = 0, end_index = window_len - 1;
    int match_count;

    if(window_len > str.size()) {
      return resultIndices;
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
        resultIndices.push_back(start_index);
      }

      char_freqs[str[start_index]]--;
      start_index++;
      end_index++;
      char_freqs[str[end_index]]++;

    } while(end_index < str.size());

    return resultIndices;
  }
};
