#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> profits = {15, 50, 60, 90};
    vector<int> weights = {1, 3, 4, 5};
    int capacity = 8;

    vector<vector<int>> dp(profits.size(), vector<int>(capacity + 1, 0));   // dp[profits.size()][capacity + 1]

    for(int j=0; j<profits.size(); j++) {
        dp[j][0] = 0;
    }

    for(int i=1; i<capacity+1; i++) {
        dp[0][i] = (i / weights[0]) * profits[0];
    }


    int profit_1, profit_2;

    for(int i=1; i<profits.size(); i++) {

        for(int j=1; j<capacity+1; j++) {

            profit_1 = dp[i-1][j]; // not include the current element
            profit_2 = 0;

            if(j - weights[i] >= 0) {
                profit_2 = profits[i] + dp[i][j - weights[i]]; // include the current element (check in the same row - as we allow same element multiple times)
            }

            dp[i][j] = max(profit_1, profit_2);

        }

    }






        /*

        OUTPUT

        0   15   30   45   60   75   90   105   120
        0   15   30   50   65   80   100   115   130
        0   15   30   50   65   80   100   115   130
        0   15   30   50   65   90   105   120   140

        */

    for(int j=0; j<profits.size(); j++) {

        for(int i=0; i<capacity+1; i++) {
            cout << dp[j][i] << "   ";
        }
        cout << endl;

    }



    cout << dp[profits.size()-1][capacity]; //140




    return 0;
}