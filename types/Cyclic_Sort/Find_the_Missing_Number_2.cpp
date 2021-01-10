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
    // XOR Method
    int missing_num = 0;

    for(int num : nums) {
      missing_num = missing_num ^ num;
    }

    for(int i=0; i<nums.size()+1; i++) {
      missing_num = missing_num ^ i;
    }

    return missing_num;
  }
};
