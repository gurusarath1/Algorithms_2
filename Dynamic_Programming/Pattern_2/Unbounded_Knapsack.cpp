/*
Given the weights and profits of ‘N’ items, we are asked to put these items in a knapsack which has a capacity ‘C’. 
The goal is to get the maximum profit from the items in the knapsack.
The only difference between the 0/1 Knapsack problem and this problem is that we are allowed to use an unlimited quantity of an item.
*/

#include <iostream>
#include <vector>

using namespace std;

int support_solve_unbounded_knapsack(vector<int> &profits, vector<int> &weights, int capacity, int current_profit, int current_index);

int solve_unbounded_knapsack(vector<int> &profits, vector<int> &weights, int capacity) {

    return support_solve_unbounded_knapsack(profits, weights, capacity, 0, 0);

}

int support_solve_unbounded_knapsack(vector<int> &profits, vector<int> &weights, int capacity, int current_profit, int current_index) {
    
    if(capacity <= 0) {
        return current_profit;
    }

    if(current_index >= profits.size()) {
        return current_profit;
    }

    
    int profit_1 = 0;

    // check if you can add the current element to the knapsack
    if(capacity - weights[current_index] >= 0) {
        profit_1 = support_solve_unbounded_knapsack(profits, weights, capacity - weights[current_index], current_profit + profits[current_index], current_index); // current_index is not incremented to allow unlimited additions into the knapsack
    }

    int profit_2 = support_solve_unbounded_knapsack(profits, weights, capacity, current_profit, current_index + 1);

    return max(profit_1, profit_2);

}


int main() {

    vector<int> profits = {15, 50, 60, 90};
    vector<int> weights = {1, 3, 4, 5};
    int capacity = 6;

    cout << solve_unbounded_knapsack(profits, weights, capacity); // 105

    return 0;
}
