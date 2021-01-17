using namespace std;

#include <iostream>
#include <vector>

class Subsets {
 public:
  static vector<vector<int>> findSubsets(const vector<int>& nums) {
    vector<vector<int>> subsets;
    vector<int> current_set;

    subsets.push_back(current_set); // Push the empty set

    for(int i=0; i<nums.size(); i++) {
      int n = subsets.size();

      for(int j=0; j<n; j++) {
        current_set = subsets[j];
        current_set.push_back(nums[i]); // Push the current number
        subsets.push_back(current_set);
      }
    }
    
    return subsets;
  }

};

int main(int argc, char* argv[]) {

  auto result = Subsets::findSubsets(vector<int>{1,2,3,4});
  cout << "Subsets are : " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
