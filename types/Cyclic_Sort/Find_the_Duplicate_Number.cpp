/*
We are given an unsorted array containing ‘n+1’ numbers taken from the range 1 to ‘n’.
The array has only one duplicate but it can be repeated multiple times.
Find that duplicate number without using any extra space. You are, however, allowed to modify the input array.
*/

using namespace std;

#include <iostream>
#include <vector>

class FindDuplicate {
 public:
  static int findNumber(vector<int> &nums) {

    for(int i=0; i<nums.size(); i++) {
      while(nums[i] != nums[nums[i] - 1]) {
        swap(nums, i, nums[i] - 1);
      }
    }

    for(int i=0; i<nums.size(); i++) {
      if(nums[i] != i + 1) {
        return nums[i];
      }
    }
    return -1;
  }

  static void swap(vector<int> &nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }

};
