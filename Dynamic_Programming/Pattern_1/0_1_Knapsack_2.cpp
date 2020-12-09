#include <iostream>
#include <vector>

using namespace std;

int main() {

    int capacity = 6;
	vector<int> profits = {1, 6, 10, 16};
	vector<int> weights = {1, 2, 3, 5};
    int num_rows = profits.size();

    int dp[num_rows][capacity+1];

    for(int i=0; i<num_rows; i++) {
        dp[i][0] = 0;
    }

    for(int j=0; j<=capacity; j++) {

        if(weights[0] <= j) {
            dp[0][j] = profits[0];
        } else {
            dp[0][j] = 0;
        }

    }

    int profit_possibility_1;
    int profit_possibility_2;

    for(int i=1; i<num_rows; i++) {
        for(int j=1; j<=capacity; j++) {

            profit_possibility_1 = dp[i-1][j]; // Do not include the item

            if(j-weights[i] >= 0) {

                profit_possibility_2 = dp[i-1][j - weights[i]] + profits[i]; // include the item
                dp[i][j] = max(profit_possibility_1, profit_possibility_2); // Check which is the better option

            } else {

                dp[i][j] = profit_possibility_1;

            }

        }
    }

    cout << dp[num_rows-1][capacity] << endl;


    // Print DP table
    for(int i=0; i<num_rows; i++) {
        for(int j=0; j<=capacity; j++) {

            cout << dp[i][j] << "    ";
        }

        cout << endl;
    }

    return 0;
}

