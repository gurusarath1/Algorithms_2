/*
Given an array containing 0s and 1s, if you are allowed to replace no more than ‘k’ 0s with 1s, find the length of the longest contiguous subarray having all 1s.

Input: Array=[0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1], k=2
Output: 6
Explanation: Replace the '0' at index 5 and 8 to have the longest contiguous subarray of 1s having length 6.

Input: Array=[0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1], k=3
Output: 9
Explanation: Replace the '0' at index 6, 9, and 10 to have the longest contiguous subarray of 1s having length 9.

*/

using namespace std;

#include <iostream>
#include <vector>

class ReplacingOnes {
 public:
  static int findLength(const vector<int>& arr, int k) {
    int  maxLength = 0;
    int start_index = 0;
    int num_zeros = 0;

    for(int end_index=0; end_index < arr.size(); end_index++) {

      if(arr[end_index] == 0) {
        num_zeros++;
      }

      while(num_zeros > k) {

        if(arr[start_index] == 0) {
          num_zeros--;
        }

        start_index++;        

      }

      if(num_zeros == k) {
        if(maxLength < end_index - start_index + 1) { 
          maxLength = end_index - start_index + 1;
        }
      }

    }

    return maxLength;
  }
};
