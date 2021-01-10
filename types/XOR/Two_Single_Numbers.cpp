/*
In a non-empty array of numbers, every number appears exactly twice except two numbers that appear only once. Find the two numbers that appear only once.
*/

using namespace std;

#include <iostream>
#include <vector>

class TwoSingleNumbers {
public:
  static vector<int> findSingleNumbers(vector<int> &nums) {

    int num1_xor_num2 = 0;

    for(int num : nums) {
      num1_xor_num2 = num1_xor_num2 ^ num;
    }

    int num_shifts=0;

    while( (num1_xor_num2 & (0x01 << num_shifts)) == 0 ) {
      num_shifts++;
    }

    vector<int> group_1, group_2;

    for(int num : nums) {
      if( (num & (0x01 << num_shifts)) == 0 ) {
        group_1.push_back(num);
      } else {
        group_2.push_back(num);
      }
    }

    int num1 = 0, num2 = 0;

    for(int num : group_1) {
      num1 = num1 ^ num;
    }

    for(int num : group_2) {
      num2 = num2 ^ num;
    }

    return vector<int>{num1, num2};
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {4,4,5,5,6,6,7,8,8,9,9,10,11,11,12,12};
  vector<int> result = TwoSingleNumbers::findSingleNumbers(v1);
  cout << "Single numbers are: " << result[0] << ", " << result[1] << endl;

  v1 = {2, 1, 3, 2, 3, 1, 7, 8};
  result = TwoSingleNumbers::findSingleNumbers(v1);
  cout << "Single numbers are: " << result[0] << ", " << result[1] << endl;
}
