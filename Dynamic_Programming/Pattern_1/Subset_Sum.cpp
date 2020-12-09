#include <iostream>
#include <vector>

using namespace std;

bool solve_subsetSum(vector<int> &input_set, int index,  int target) {

    if(target == 0) {
        return true;
    }

    if(index >= input_set.size()) {
        return false;
    }

            // include number                                               // dont include
    return solve_subsetSum(input_set, index+1, target-input_set[index]) || solve_subsetSum(input_set, index+1, target);

}


int main() {

    vector<int> set = {1, 2, 3, 7};
    int S=9;

    cout << solve_subsetSum(set, 0, S);


    return 0;
}