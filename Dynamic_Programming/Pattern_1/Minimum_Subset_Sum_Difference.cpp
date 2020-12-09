#include <iostream>
#include <vector>

using namespace std;

int support_solve_Minimum_Subset_Sum_Difference(vector<int> &set, int index, int sum1, int sum2);

int solve_Minimum_Subset_Sum_Difference(vector<int> &set) {

    return support_solve_Minimum_Subset_Sum_Difference(set, 0, 0, 0);

}

int support_solve_Minimum_Subset_Sum_Difference(vector<int> &set, int index, int sum1, int sum2) {

    if(index >= set.size()) {
        return abs(sum1-sum2);
    }

    int diff_1 = support_solve_Minimum_Subset_Sum_Difference(set, index+1, sum1 + set[index], sum2);
    int diff_2 = support_solve_Minimum_Subset_Sum_Difference(set, index+1, sum1, sum2 + set[index]);

    return min(diff_1, diff_2);

}


int main() {

    vector<int> set = {1, 2, 3, 9};

    int min_sum_diff = solve_Minimum_Subset_Sum_Difference(set);

    cout << min_sum_diff; // 3

    return 0;
}