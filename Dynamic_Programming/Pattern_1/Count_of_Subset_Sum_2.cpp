#include <iostream>
#include <vector>

using namespace std;

int support_solve_Count_of_Subset_Sum(vector<int> &set, int index, int current_sum, int target_sum, vector<vector<int>> &memo);

int solve_Count_of_Subset_Sum(vector<int> &set, int target_sum) {

    vector<vector<int>> memo(set.size(), vector<int>(target_sum+1, -1));

    return support_solve_Count_of_Subset_Sum(set, 0, 0, target_sum, memo);

}

int support_solve_Count_of_Subset_Sum(vector<int> &set, int index, int current_sum, int target_sum, vector<vector<int>> &memo) {

    if(current_sum > target_sum) {
        return 0;
    }

    if(current_sum == target_sum) {
        return 1;
    }

    if(index >= set.size()) return 0;

    if(memo[index][current_sum] != -1) {
        return memo[index][current_sum];
    }

    int sum = support_solve_Count_of_Subset_Sum(set, index+1, current_sum, target_sum, memo) + support_solve_Count_of_Subset_Sum(set, index+1, current_sum + set[index], target_sum, memo);

    memo[index][current_sum] = sum;

    return sum;

}


int main() {

    vector<int> set = {1, 1, 2, 3}; 
    int target_sum = 4;

    int count = solve_Count_of_Subset_Sum(set, target_sum);

    cout << count; // 3

    return 0;
}
