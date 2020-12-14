/*
Equal Subset Sum Partition - 
Given a set of positive numbers, find if we can partition it into two subsets such that the sum of elements in both the subsets is equal.
*/

using namespace std;

#include <iostream>
#include <vector>

class PartitionSet {
public:
  bool canPartition(const vector<int> &num) {
    
    int sum = 0;

    for(int x : num) {
      sum += x;
    }

    int target_sum = sum / 2;

    if( sum % 2 != 0) {
      return 0;
    }

    int num_rows = num.size();

    cout << num_rows << "     " << target_sum << endl;
    
    bool dp[num_rows][target_sum + 1];

    for(int i=0; i<num_rows; i++) {
      dp[i][0] = true;
    }

    for(int s=1; s<target_sum+1; s++) {
      if(s == target_sum) {

        dp[0][s] = true;

      } else {

        dp[0][s] = false;

      }
    }

    for(int i=1; i<num_rows; i++) {
      for(int s=1; s<target_sum+1; s++) {

        if(dp[i-1][s] == true) {
          dp[i][s] = true;
        } else if(dp[i-1][s - num[i]] ==  true) {
          dp[i][s] = true;
        } else {
          dp[i][s] = false;
        }

      }
    }

    cout << target_sum << endl;

    for(int i=0; i<num_rows; i++) {
      for(int s=0; s<target_sum+1; s++) {

        cout << dp[i][s] << "   ";

      }

      cout << endl;
    }

    return dp[num_rows-1][target_sum];
  }
};
