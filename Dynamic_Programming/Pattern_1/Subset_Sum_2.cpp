#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> set = {1, 3, 4, 8};
    int Sum=10;
    int num_rows = set.size();

    bool dp[num_rows][Sum+1];

    // Fill first col
    for(int i=0; i<num_rows; i++) {
        dp[i][0] = true;
    }


    // Fill first row
    for(int s=1; s<=Sum; s++) {

        if(set[0] == s) dp[0][s] = true;
        else dp[0][s] = false;
    }


    for(int i=1; i<num_rows; i++) {
        for(int s=1; s<=Sum; s++) {

            // Can we achieve the sum without including the current number ?
            if( dp[i-1][s] == true ) {

                dp[i][s] = true;

            // Can we include the number and achieve the sum
            } else if (s - set[i] >= 0) {

                if( dp[i-1][s-set[i]] == true ) {
                    dp[i][s] = true;
                } else {
                    dp[i][s] = false;
                }

            } else {

                dp[i][s] = false;

            }

        }
    }

    cout << dp[num_rows-1][Sum] << endl;

    for(int i=0; i<num_rows; i++) {
        for(int s=0; s<=Sum; s++) {

            cout << dp[i][s] << "   ";
        }

        cout << endl;
    }

    return 0;
}

/*

0
1   1   0   0   0   0   0   0   0   0   0
1   1   0   1   1   0   0   0   0   0   0
1   1   0   1   1   1   0   1   1   0   0
1   1   0   1   1   1   0   1   1   1   0


*/