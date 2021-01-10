/*

We are given an array containing ‘n’ distinct numbers taken from the range 0 to ‘n’.
Since the array has only ‘n’ numbers out of the total ‘n+1’ numbers, find the missing number.

*/

using namespace std;

#include <iostream>
#include <vector>

class MissingNumber {
 public:
  static int findMissingNumber(vector<int> &nums) {
    
    // Hasing Method
    vector<bool> nums_hash(nums.size() + 1);

    for(int num : nums) {
      nums_hash[num] = true;
    }

    for(int i=0; i<nums_hash.size(); i++) {
      if(!nums_hash[i]) {
        return i;
      }
    }

    return -1;
  }
};
