/*
Given a sorted array of numbers, find if a given number ‘key’ is present in the array. 
Though we know that the array is sorted, we don’t know if it’s sorted in ascending or descending order. You should assume that the array can have duplicates.
Write a function to return the index of the ‘key’ if it is present in the array, otherwise return -1.
*/

using namespace std;

#include <iostream>
#include <vector>

class BinarySearch {
 public:
  static int search(const vector<int>& arr, int key) {
    // TODO: Write your code here

    int left = 0;
    int right = arr.size() - 1;
    bool ascending;
    int mid;

    if(arr[0] > arr[arr.size() - 1]) { 
      ascending = false;
    } else {
      ascending = true;
    }

    while(left <= right) {

      mid = left + (right - left)/2;

      if(arr[mid] == key) {
        return mid;
      }

      if(ascending) {

        if(arr[mid] > key) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }

      } else {

        if(arr[mid] < key) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }

      }

    }


    return -1; 
  }
};

int main(int argc, char* argv[]) {
  cout << BinarySearch::search(vector<int>{4, 6, 10}, 10) << endl;
  cout << BinarySearch::search(vector<int>{1, 2, 3, 4, 5, 6, 7}, 5) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 10) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 4) << endl;
}
