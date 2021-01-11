using namespace std;

#include <iostream>
#include <vector>

class MissingNumber {
 public:
  static int findMissingNumber(vector<int> &nums) {
    // Cyclic Sort Method
    int i=0;
    while(i < nums.size()) {
      if(!(nums[i] == nums.size()) && nums[i] != i) {
        swap(nums, i, nums[i]);
      } else {
        i++;
      }
    }

    for(int i=0; i<nums.size(); i++) {
      if(nums[i] != i) {
        return i;
      }
    }

    return -1;
  }

  static void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }

};
