/*
Given an array of sorted numbers, remove all duplicates from it. 
You should not use any extra space; after removing the duplicates in-place return the length of the subarray that has no duplicate in it.
*/

using namespace std;

#include <iostream>
#include <vector>

class RemoveDuplicates {
 public:
  static int remove(vector<int>& arr) {

    int current_num;
    int j;
    vector<int>::iterator it = arr.begin();

    for(int i=0; i<arr.size(); i++) {
      current_num = arr[i];
      j = i + 1;

      while(j < arr.size() && arr[j] == current_num) {
        arr.erase(it + j);
      }
    }

    return arr.size();
  }
};
