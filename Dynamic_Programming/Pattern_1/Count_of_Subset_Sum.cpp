#include <iostream>
#include <vector>

using namespace std;

int support_solve_Count_of_Subset_Sum(vector<int> &set, int index, int current_sum, int target_sum);

int solve_Count_of_Subset_Sum(vector<int> &set, int target_sum) {

    return support_solve_Count_of_Subset_Sum(set, 0, 0, target_sum);

}

int support_solve_Count_of_Subset_Sum(vector<int> &set, int index, int current_sum, int target_sum) {

    if(current_sum > target_sum) {
        return 0;
    }

    if(current_sum == target_sum) {
        return 1;
    }

    if(index >= set.size()) return 0;

    return support_solve_Count_of_Subset_Sum(set, index+1, current_sum, target_sum) + support_solve_Count_of_Subset_Sum(set, index+1, current_sum + set[index], target_sum);

}


int main() {

    vector<int> set = {1, 2, 7, 1, 5};
    int target_sum = 9;

    int count = solve_Count_of_Subset_Sum(set, target_sum);

    cout << count; // 3

    return 0;
}
