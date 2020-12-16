/*
Given a set of positive numbers (non zero) and a target sum ‘S’. 
Each number should be assigned either a ‘+’ or ‘-’ sign. 
We need to find out total ways to assign symbols to make the sum of numbers equal to target ‘S’.

Example 1:
Input: {1, 1, 2, 3}, S=1
Output: 3
Explanation: The given set has '3' ways to make a sum of '1': {+1-1-2+3} & {-1+1-2+3} & {+1+1+2-3}
*/


#include <iostream>
#include <vector>

using namespace std;

int support_solve_target_sum(vector<int> &nums, int target_sum, int current_index, int current_sum);

int solve_target_sum(vector<int> &nums, int target_sum) {

    return support_solve_target_sum(nums, target_sum, 0, 0);

}

int support_solve_target_sum(vector<int> &nums, int target_sum, int current_index, int current_sum) {

    if(current_index == nums.size()) {
        if(current_sum == target_sum) {
            return 1;
        } else {
            return 0;
        }
    }

    int path_1 = support_solve_target_sum(nums, target_sum, current_index + 1, current_sum + nums[current_index]);
    int path_2 = support_solve_target_sum(nums, target_sum, current_index + 1, current_sum - nums[current_index]);

    return path_1 + path_2;

}


int main() {

    vector<int> nums = {1, 1, 2, 3};
    int sum = 1;

    cout << solve_target_sum(nums, sum);

    return 0;
}
