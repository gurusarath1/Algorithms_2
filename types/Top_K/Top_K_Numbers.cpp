/*
Given an unsorted array of numbers, find the ‘K’ largest numbers in it.
*/

using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class KLargestNumbers {
 public:
  static vector<int> findKLargestNumbers(const vector<int>& nums, int k) {
    vector<int> result;
    priority_queue<int> max_heap;

    for(int i=0; i<nums.size(); i++) {
      max_heap.push(nums[i]);
    }

    for(int i=0; i<k; i++) {
      result.push_back(max_heap.top());
      max_heap.pop();
    }

    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result = KLargestNumbers::findKLargestNumbers(vector<int>{3, 1, 5, 12, 2, 11}, 3);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = KLargestNumbers::findKLargestNumbers(vector<int>{5, 12, 11, -1, 12}, 3);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
