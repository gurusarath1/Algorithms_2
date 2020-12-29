#include <iostream>
#include <vector>

using namespace std;

int support_solve_rod_cutting(vector<int> &lengths, vector<int> &prices, int rod_len, vector<int> memo);

int solve_rod_cutting(vector<int> &lengths, vector<int> &prices, int rod_len) {

    vector<int> memo(rod_len+1, -1);

    return support_solve_rod_cutting(lengths, prices, rod_len, memo);

}

int support_solve_rod_cutting(vector<int> &lengths, vector<int> &prices, int rod_len, vector<int> memo) {

    int max_profit = 0;
    int profit, cut_len;

    if(rod_len == 0) {
        return 0;
    }

    if(memo[rod_len] != -1) {
        return memo[rod_len];
    }

    for(int i=0; i<lengths.size(); i++) {

        cut_len = lengths[i];

        // Check if it is possible to make the cut
        if(cut_len <= rod_len) { 
            profit = prices[i] + support_solve_rod_cutting(lengths, prices, rod_len - cut_len, memo);

            if(profit > max_profit) {
                max_profit = profit;
            }
        }

    }

    memo[rod_len] = max_profit;

    return max_profit;
    
}


int main() {

    vector<int> lengths = {1, 2, 3, 4};
    vector<int> prices = {2,5,7,8};
    int rod_len = 5;


    cout << solve_rod_cutting(lengths, prices, rod_len); //12

    return 0;
}