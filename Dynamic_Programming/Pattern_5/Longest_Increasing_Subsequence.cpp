#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> arr = {-4,10,3,7,15};
    vector<int> dp(arr.size(), 1); // LIS will atleast have a length 1


    for(int i=0; i<arr.size(); i++) {

        for(int k=0; k<i; k++) {

            if(arr[k] < arr[i] && dp[i] < dp[k] + 1) {
                dp[i] = dp[k] + 1;
            }

        }

    }

    // Print dp 
    // 1   2   2   3   4

    for(int i=0; i<dp.size(); i++) {
        cout << dp[i] << "   ";
    }

    cout << endl << dp[dp.size() - 1]; // 4

    return 0;
}