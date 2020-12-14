/*
Given two integer arrays to represent weights and profits of ‘N’ items, 
we need to find a subset of these items which will give us maximum profit such that their cumulative weight is not more than a given number ‘C’. 
Each item can only be selected once, which means either we put an item in the knapsack or skip it.
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solve_knapsack_support(int current_index, int current_profit, vector<int>& profits, vector<int>& weights, map<int, int> &memo, int capacity);

int solve_knapsack(vector<int>& profits, vector<int>& weights, int capacity) {

	map<int, int> memo;

	int bestProfit = solve_knapsack_support(0, 0, profits, weights, memo, capacity);

	return bestProfit;
}


int solve_knapsack_support(int current_index, int current_profit, vector<int>& profits, vector<int>& weights, map<int, int> &memo, int capacity) {

	if (current_index >= profits.size() || capacity <= 0) {
		return current_profit;
	}

	if(memo[capacity] != 0) {
		return memo[capacity];
	}


	int profit_1;
	
	if(capacity - weights[current_index] >= 0) {
		profit_1 = solve_knapsack_support(current_index + 1, current_profit + profits[current_index], profits, weights, memo, capacity - weights[current_index]);
	} else {
		profit_1 = current_profit;
	}
	
	int profit_2 = solve_knapsack_support(current_index + 1, current_profit, profits, weights, memo, capacity);

	if(profit_1 > profit_2) {

		memo[capacity] = profit_1;
		return profit_1;

	} else {

		memo[capacity] = profit_2;
		return profit_2;
	}

}




int main() {

	vector<int> profits = {1, 6, 10, 16};
	vector<int> weights = {1, 2, 3, 5};

	cout << solve_knapsack(profits, weights, 6);


	return 0;
}
