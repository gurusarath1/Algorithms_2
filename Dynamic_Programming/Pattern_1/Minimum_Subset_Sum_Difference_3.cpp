#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> set = {1,2,3,9};

    int sum = 0;

    for (int i : set) {
        sum += i;
    }

    // We want the sum to be as close as possible to Sum/2

    int sum_by_2 = (int) (sum / 2) + 1;
    int num_rows = set.size();

    bool dp[num_rows][sum_by_2 + 1];

    for(int i=0; i<num_rows; i++) {
        dp[i][0] = true;
    }

    for(int s=1; s<=sum_by_2; s++) {
        if(set[0] == s) {
            dp[0][s] = true;
        } else {
            dp[0][s] = false;
        }
    }

    for(int i=1; i<num_rows; i++) {

        for(int s=1; s<=sum_by_2; s++) {

            if(dp[i-1][s] == true) {
                dp[i][s] = true;
            } else if(s - set[i] >= 0 && dp[i-1][s - set[i]] == true) {
                dp[i][s] = true;
            } else {
                dp[i][s] = false;
            }

        }

    }

    int max_possible_sum = 0;
    for(int s=sum_by_2; s >= 0; s--) {
        if(dp[num_rows-1][s] == true) {
            max_possible_sum = s;
            break;
        }
    }

    int min_diff = abs(sum - max_possible_sum - max_possible_sum);

    cout << min_diff << endl;

    for(int i=1; i<num_rows; i++) {
        for(int s=1; s<=sum_by_2; s++) {
            cout << dp[i][s];
        }
        cout << endl;
    }

    /*
        1
        1011000
        1011101
        1111111
        1111111
        1111111
    */

    return 0;
}