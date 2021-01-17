using namespace std;

#include <iostream>
#include <vector>

class Subsets {
 public:
  static vector<vector<int>> findSubsets(const vector<int>& nums) {
    vector<vector<int>> subsets;
    vector<int> current_set;
    support_findSubsets(nums, 0, current_set, subsets);
    
    return subsets;
  }

  static void support_findSubsets(const vector<int>& nums, int current_index, vector<int> &current_set, vector<vector<int>> &subsets) {

    if(current_index > nums.size() - 1) {
      subsets.push_back(current_set); // Push the formed set
      return;
    }

    support_findSubsets(nums, current_index+1, current_set, subsets); // Dont include the number in the set

    current_set.push_back(nums[current_index]);

    support_findSubsets(nums, current_index+1, current_set, subsets); // include the number in the set

    current_set.erase(current_set.end() - 1);

    return;
  }
};

int main(int argc, char* argv[]) {

  auto result = Subsets::findSubsets(vector<int>{1,2,3,4,5,6});
  cout << "Subsets are : " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
