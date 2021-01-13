/*
We are given an unsorted array containing ‘n’ numbers taken from the range 1 to ‘n’.
The array originally contained all the numbers from 1 to ‘n’, but due to a data error, one of the numbers got duplicated which also resulted in one number going missing.
Find both these numbers.
*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

class FindCorruptNums {
 public:
  static vector<int> findNumbers(vector<int> &nums) {

    for(int i=0; i<nums.size(); i++) {

      while(nums[i] != nums[nums[i] - 1]) {
        swap(nums, i, nums[i] - 1);
      }

    }

    for(int i=0; i<nums.size(); i++) {

      if(nums[i] != i + 1) {
        return vector<int>{nums[i], i+1};
      }

    }

    return vector<int>{-1, -1};
  }

  static void swap(vector<int> &nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }

};
