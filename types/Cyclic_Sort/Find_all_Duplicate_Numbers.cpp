using namespace std;

#include <iostream>
#include <vector>

class FindAllDuplicate {
 public:
  static vector<int> findNumbers(vector<int> &nums) {
    vector<int> duplicateNumbers;

    for(int i=0; i<nums.size(); i++) {
      while(nums[i] != nums[nums[i] - 1]) {
        swap(nums, i, nums[i] - 1);
      }
    }

    for(int i=0; i<nums.size(); i++) {
      if(nums[i] != i + 1) {
        duplicateNumbers.push_back(nums[i]);
      }
    }
    return duplicateNumbers;
  }

  static void swap(vector<int> &nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }

};
