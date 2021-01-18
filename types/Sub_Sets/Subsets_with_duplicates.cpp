using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class SubsetWithDuplicates {
 public:
  static vector<vector<int>> findSubsets(vector<int>& nums) {
    vector<vector<int>> subsets;
    vector<vector<int>> prev_subsets;

    sort(nums.begin(), nums.end()); // Sort the input sequence so that all the duplicates are together.

    subsets.push_back(vector<int>());
    
    for(int i=0; i<nums.size(); i++) {

      if ( (i == 0) || (i > 0 && nums[i] != nums[i-1]) ) { // If the current number is not a duplicate

        int n = subsets.size();
        prev_subsets.clear();
        for(int j=0; j<n; j++) {

          vector<int> subsetX = subsets[j];
          subsetX.push_back(nums[i]);
          subsets.push_back(subsetX);
          prev_subsets.push_back(subsetX);

        }

      } else { // Duplicate detected

        int n = prev_subsets.size();
        for(int j=0; j<n; j++) {
          prev_subsets[j].push_back(nums[i]);
          subsets.push_back(prev_subsets[j]);
        }

      }

    }

    return subsets;
  }
};

int main(int argc, char* argv[]) {
  vector<int> vec = {1, 3, 3};
  vector<vector<int>> result = SubsetWithDuplicates::findSubsets(vec);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  vec = {1, 5, 3, 3};
  result = SubsetWithDuplicates::findSubsets(vec);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
