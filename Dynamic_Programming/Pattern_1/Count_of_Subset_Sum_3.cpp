/*
Given a set of positive numbers, find the total number of subsets whose sum is equal to a given number ‘S’.
*/

using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
public:
  int countSubsets(const vector<int> &num, int sum) {
    
    int num_rows = num.size();
    
    int dp[num_rows][sum+1];

    for(int i=0; i<num_rows; i++) {
      dp[i][0] = 1;
    }

    for(int s=1; s<sum+1; s++) {

      if(s == num[0]) {
        dp[0][s] = 1;
      } else {
        dp[0][s] = 0;
      }
    }

    for(int i=1; i<num_rows; i++) {
      for(int s=1; s<sum+1; s++) {

        dp[i][s] = dp[i-1][s];
        
        if(s - num[i] >= 0) {
          dp[i][s] += dp[i-1][s - num[i]];
        }

      }
    }


    /*

    INPUT - countSubsets(1,1,2,3, 4)
    OUTPUT - 3

    dp
    1   1   0   0   0   0   0   0   0   0   
    1   1   1   1   0   0   0   0   0   0   
    1   1   1   1   0   0   0   1   1   1   
    1   2   2   2   1   0   0   1   2   2   
    1   2   2   2   1   1   2   3   4   3 

    */


    return dp[num_rows-1][sum];
  }
};
