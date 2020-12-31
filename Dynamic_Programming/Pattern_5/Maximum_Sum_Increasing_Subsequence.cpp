#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> arr = {1, 101, 2, 3, 100, 4, 5}; 
    vector<int> dp(arr.size());
    int max_sum = arr[0];
    int max_sum_local;

    dp = arr;

    for(int i=0; i<arr.size(); i++) {

        max_sum_local = dp[i];
        for(int k=0; k<i; k++) {
            if(arr[k] < arr[i] && dp[k] + dp[i] > max_sum_local) {
                max_sum_local = dp[k] + dp[i];
            }
        }

        dp[i] = max_sum_local;

        if(max_sum < dp[i]) {
            max_sum = dp[i];
        }
    }



    // Print DP

    for(int i=0; i<dp.size(); i++) {

        cout << dp[i] << "   ";

    } // 1   102   3   6   106   10   15


    cout << endl << max_sum; // 106



    return 0;
}