using namespace std;

#include <iostream>
#include <vector>

class MaxSumSubArrayOfSizeK {
 public:
  static int findMaxSumSubArray(int k, const vector<int>& arr) {
    int maxSum = 0;
    int start_index = 0;
    int end_index = k-1;
    int WindowSum = 0;

    for(int i=0; i<k; i++) {

      if(i < k) {
        WindowSum += arr[i];
      } else {
        return WindowSum;
      }

    }

    while(1) {

      if(WindowSum > maxSum) {
        maxSum = WindowSum;
      }

      start_index += 1;
      end_index += 1;

      if(end_index >= arr.size()) break;

      WindowSum -= arr[start_index - 1];
      WindowSum += arr[end_index];

    }

    return maxSum;

  }
};
