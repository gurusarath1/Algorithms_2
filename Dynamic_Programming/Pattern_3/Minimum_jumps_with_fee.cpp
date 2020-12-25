#include <iostream>
#include <vector>

using namespace std;

int support_solve_Minimum_jumps_with_fee(vector<int> &step_costs, int current_step, int current_cost);

int solve_Minimum_jumps_with_fee(vector<int> &step_costs) {

    return support_solve_Minimum_jumps_with_fee(step_costs, 0, 0);

}

int support_solve_Minimum_jumps_with_fee(vector<int> &step_costs, int current_step, int current_cost) {

    if(current_step > step_costs.size()) {
        return INT_MAX;
    }

    if(current_step == step_costs.size()) {
        return current_cost;
    }


    int cost_1 = INT_MAX;
    if(current_step + 1 <= step_costs.size()) {
        cost_1 = support_solve_Minimum_jumps_with_fee(step_costs, current_step + 1, current_cost + step_costs[current_step]);
    }

    int cost_2 = INT_MAX;
    if(current_step + 2 <= step_costs.size()) {
        cost_2 = support_solve_Minimum_jumps_with_fee(step_costs, current_step + 2, current_cost + step_costs[current_step]);
    }

    int cost_3 = INT_MAX;
    if(current_step + 3 <= step_costs.size()) {
        cost_3 = support_solve_Minimum_jumps_with_fee(step_costs, current_step + 3, current_cost + step_costs[current_step]);
    }

    return min(cost_1, min(cost_2,cost_3));

}

int main() {

    vector<int> x = {2,3,4,5};
    vector<int> y = {1,2,5,2,1,2};

    cout << solve_Minimum_jumps_with_fee(x) << endl; // 5
    cout << solve_Minimum_jumps_with_fee(y); // 3

    return 0;
}
