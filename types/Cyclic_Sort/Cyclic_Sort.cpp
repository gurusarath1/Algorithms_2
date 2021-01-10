/*

We are given an array containing ‘n’ objects. Each object, when created, was assigned a unique number from 1 to ‘n’ based on their creation sequence.
This means that the object with sequence number ‘3’ was created just before the object with sequence number ‘4’.

Write a function to sort the objects in-place on their creation sequence number in O(n)O(n)O(n) and without any extra space.
For simplicity, let’s assume we are passed an integer array containing only the sequence numbers, though each number is actually an object.

*/

using namespace std;

#include <iostream>
#include <vector>

class CyclicSort {
 public:
  static void sort(vector<int> &nums) {

    int temp_num;

    for(int i=0; i<nums.size(); i++) {
      while(nums[i] != i+1) {
        temp_num = nums[nums[i] - 1];
        nums[nums[i] - 1] = nums[i];
        nums[i] = temp_num;
      }
    }


  }
};
