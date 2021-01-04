/*
Given a string, find the length of the longest substring in it with no more than K distinct characters.

Input: String="araaci", K=2
Output: 4
Explanation: The longest substring with no more than '2' distinct characters is "araa".

Input: String="cbbebi", K=3
Output: 5
Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".

*/


using namespace std;

#include <iostream>
#include <string>
#include <set>

class LongestSubstringKDistinct {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;
    int start_index = 0;
    set<char> items_in_window;

    for(int end_index=0; end_index < str.size(); end_index++) {

      items_in_window.insert(str[end_index]);

      // Reduce the size of the window when number of unique characters becomes greater than k
      while(items_in_window.size() > k) {
        items_in_window.erase(str[start_index]);
        start_index++;
      }

      if(items_in_window.size() == k) {

        if(maxLength < end_index - start_index + 1) {
          maxLength = end_index - start_index + 1;
        }

      }

    }

    return maxLength;
  }
};
