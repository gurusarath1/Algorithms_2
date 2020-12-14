/*
Given an array of positive numbers and a positive number ‘S,’ find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’. 
Return 0 if no such subarray exists.
*/

using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {

    int start_index = 0;
    int end_index = 0;
    int window_sum = 0;
    int min_window_size = numeric_limits<int>::max();


    // This loop slides the main window
    for(end_index = 0; end_index < arr.size(); end_index++) {

      window_sum += arr[end_index];

      cout << start_index << "   " << end_index << " --- " << window_sum << endl;

      // This loop changes the size of the window
      while(window_sum >= S) {
        if(end_index - start_index + 1 < min_window_size) {
          min_window_size = end_index - start_index + 1;
          cout << "Updated " << min_window_size << endl;
        }

        start_index += 1;
        window_sum -= arr[start_index - 1];

        cout << start_index << "   " << end_index << " --- " << window_sum << endl;
      }
    }


    if(min_window_size > arr.size()) {
      min_window_size = 0;
    }


    return min_window_size;
  }
};
