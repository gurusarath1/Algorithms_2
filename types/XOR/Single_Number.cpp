/*
In a non-empty array of integers, every number appears twice except for one, find that single number.
*/

using namespace std;

#include <iostream>
#include <vector>

class SingleNumber {
  public:
    static int findSingleNumber(const vector<int>& arr) {
      int missing_number = 0;

      for(int num : arr) {
        missing_number = missing_number ^ num;
      }

      return missing_number;
    }
};

int main(int argc, char* argv[]) {
  cout << SingleNumber::findSingleNumber(vector<int>{1, 4, 2, 1, 3, 2, 3}) << endl;
}
