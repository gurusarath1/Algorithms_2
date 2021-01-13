/*
We are given an unsorted array containing numbers taken from the range 1 to ‘n’.
The array can have duplicates, which means some numbers will be missing. Find all those missing numbers.
*/

using namespace std;

#include <iostream>
#include <vector>

class AllMissingNumbers {
 public:
  static vector<int> findNumbers(vector<int> &nums) {
    vector<int> missingNumbers;
    
    for(int i=0; i<nums.size(); i++) {

      while(nums[i] != nums[nums[i] - 1]) {
        swap(nums, i, nums[i] - 1);
      }

    }
    
    for(int i=0; i<nums.size(); i++) {
      if(nums[i] - 1 != i) {
        missingNumbers.push_back(i+1);
      }
    }

    return missingNumbers;
  }

  static void swap(vector<int> &nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
};
