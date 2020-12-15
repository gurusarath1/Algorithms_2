/*
Given a sorted array, create a new array containing squares of all the numbers of the input array in the sorted order.
Input: [-2, -1, 0, 2, 3]
Output: [0, 1, 4, 4, 9]
*/

using namespace std;

#include <iostream>
#include <vector>

class SortedArraySquares {
 public:
  static vector<int> makeSquares(const vector<int>& arr) {
    int n = arr.size();
    vector<int> squares(n);

    int pointer_1 = 0;
    int pointer_2 = arr.size() - 1;
    int pointer_result_filler = squares.size() - 1;
    int sqr_1, sqr_2;

    while(pointer_1 < pointer_2) {

      sqr_1 = arr[pointer_1] * arr[pointer_1];
      sqr_2 = arr[pointer_2] * arr[pointer_2];

      if(sqr_1 > sqr_2) {

        squares[pointer_result_filler] = sqr_1;
        pointer_result_filler--;
        pointer_1++;

      } else {

        squares[pointer_result_filler] = sqr_2;
        pointer_result_filler--;
        pointer_2--;

      }

    }

    return squares;
  }
};
