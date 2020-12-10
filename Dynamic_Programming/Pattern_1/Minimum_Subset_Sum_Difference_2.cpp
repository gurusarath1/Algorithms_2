#include <iostream>
#include <vector>

using namespace std;

int support_solve_Minimum_Subset_Sum_Difference(vector<int> &set, int index, int sum1, int sum2, vector< vector<int> > &memo );

int solve_Minimum_Subset_Sum_Difference(vector<int> &set) {

    int sum = 0;

    for(int num : set) {

        sum += num;

    }

    vector<vector<int>> memo(set.size(), vector<int>(sum + 1, -1));

    return support_solve_Minimum_Subset_Sum_Difference(set, 0, 0, 0, memo);

}

int support_solve_Minimum_Subset_Sum_Difference(vector<int> &set, int index, int sum1, int sum2, vector< vector<int> > &memo ) {

    if(index >= set.size()) {
        return abs(sum1-sum2);
    }

    if(memo[index][sum1] != -1) {
        return memo[index][sum1];
    }

    int diff_1 = support_solve_Minimum_Subset_Sum_Difference(set, index+1, sum1 + set[index], sum2, memo);
    int diff_2 = support_solve_Minimum_Subset_Sum_Difference(set, index+1, sum1, sum2 + set[index], memo);

    int min_diff = min(diff_1, diff_2);

    memo[index][sum1] = min_diff;

    return min_diff;

}


int main() {

    vector<int> set = {3, 1, 4, 2, 2, 1};

    int min_sum_diff = solve_Minimum_Subset_Sum_Difference(set);

    cout << min_sum_diff; // 1

    return 0;
}