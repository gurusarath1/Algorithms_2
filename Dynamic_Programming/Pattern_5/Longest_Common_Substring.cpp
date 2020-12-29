#include <iostream>
#include <vector>

using namespace std;

int main() {

    string s1 = "xyzabcd";
    string s2 = "abcdxyz";
    
    int max_len = 0;

    int dp[s1.size() + 1][s2.size() + 1];

    for(int i=0; i<s1.size()+1; i++) {
        dp[i][0] = 0;
    }

    for(int j=0; j<s2.size()+1; j++) {
        dp[0][j] = 0;
    }

    for(int i=1; i<s1.size()+1; i++) {
        for(int j=1; j<s2.size()+1; j++) {

            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = 0;
            }

            if(max_len < dp[i][j]) {
                max_len = dp[i][j];
            }

        }
    }


    /*

    0   0   0   0   0   0   0   0
    0   0   0   0   0   1   0   0
    0   0   0   0   0   0   2   0
    0   0   0   0   0   0   0   3
    0   1   0   0   0   0   0   0
    0   0   2   0   0   0   0   0
    0   0   0   3   0   0   0   0
    0   0   0   0   4   0   0   0

    */

    for(int i=0; i<s1.size()+1; i++) {
        for(int j=0; j<s2.size()+1; j++) {

            cout << dp[i][j] << "   ";

        }

        cout << endl;
    }

    cout << max_len; // 4

    return 0;
}
