/*
Given an array of sorted numbers and a target sum, find a pair in the array whose sum is equal to the given target.
*/

using namespace std;

#include <iostream>
#include <vector>

class PairWithTargetSum {
 public:
  static pair<int, int> search(const vector<int>& arr, int targetSum) {

    int pointer_1 = 0;
    int pointer_2 = arr.size() - 1;

    while(pointer_1 < pointer_2) {

      if(targetSum == (arr[pointer_1] + arr[pointer_2])) {

        return make_pair(pointer_1, pointer_2);

      } else if(targetSum > (arr[pointer_1] + arr[pointer_2])) {

        pointer_1++;

      } else {

        pointer_2--;

      }

    }

    return make_pair(-1, -1); // Not found
  }
};
