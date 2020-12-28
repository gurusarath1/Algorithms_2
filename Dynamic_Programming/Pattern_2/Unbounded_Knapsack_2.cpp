/*
Given the weights and profits of ‘N’ items, we are asked to put these items in a knapsack which has a capacity ‘C’. 
The goal is to get the maximum profit from the items in the knapsack.
The only difference between the 0/1 Knapsack problem and this problem is that we are allowed to use an unlimited quantity of an item.
*/

#include <iostream>
#include <vector>

using namespace std;

int support_solve_unbounded_knapsack(vector<int> &profits, vector<int> &weights, int capacity, int current_index, vector<vector<int>> &memo);

int solve_unbounded_knapsack(vector<int> &profits, vector<int> &weights, int capacity) {

    vector<vector<int>> memo(profits.size(), vector<int>(capacity + 1, 0));

    int ans =  support_solve_unbounded_knapsack(profits, weights, capacity, 0, memo);

    return ans;

}

int support_solve_unbounded_knapsack(vector<int> &profits, vector<int> &weights, int capacity, int current_index, vector<vector<int>> &memo) {
    
    if(capacity == 0) {
        return 0;
    }

    if(current_index >= profits.size()) {
        return 0;
    }

    if(memo[current_index][capacity] != 0) {
        return memo[current_index][capacity];
    }
    
    int profit_1 = 0;

    // check if you can add the current element to the knapsack
    if(capacity - weights[current_index] >= 0) {
        profit_1 = profits[current_index] + support_solve_unbounded_knapsack(profits, weights, capacity - weights[current_index], current_index, memo); // current_index is not incremented to allow unlimited additions into the knapsack
    }

    int profit_2 = support_solve_unbounded_knapsack(profits, weights, capacity, current_index + 1, memo);

    int best_profit = max(profit_1, profit_2);

    memo[current_index][capacity] = best_profit;

    return best_profit;

}


int main() {

    vector<int> profits = {10, 30, 20};
    vector<int> weights = {5, 10, 15};
    int capacity = 100;

    cout << solve_unbounded_knapsack(profits, weights, capacity); // 300

    return 0;
}
