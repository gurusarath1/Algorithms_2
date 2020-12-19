/*
Given an array of numbers sorted in an ascending order, find the ceiling of a given number ‘key’.
The ceiling of the ‘key’ will be the smallest element in the given array greater than or equal to the ‘key’.
Write a function to return the index of the ceiling of the ‘key’. If there isn’t any ceiling return -1.
*/

using namespace std;

#include <iostream>
#include <vector>

class CeilingOfANumber {
 public:
  static int searchCeilingOfANumber(const vector<int>& arr, int key) {
    
    int left = 0;
    int right = arr.size() - 1;

    int mid;

    if(key > arr[arr.size() - 1]) {
      return -1;
    }

    while(left <= right) {

      mid = left + (right - left) / 2;

      if(arr[mid] == key) {

        return mid;

      } else if(arr[mid] > key) {

        right = mid - 1;

      } else {

        left = mid + 1;

      }

    }

    return left;
  }
};

int main(int argc, char* argv[]) {
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 6}, 6) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, 17) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, -1) << endl;
}
