/*
Given an array of unsorted numbers, find all unique triplets in it that add up to zero.
*/

using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class TripletSumToZero {
 public:
  static vector<vector<int>> searchTriplets(vector<int> &arr) {

    vector<vector<int>> triplets;
    int target;
    sort(arr.begin(), arr.end());

    for(int i=0; i<arr.size() - 2; i++) {

      // Skip repeated numbers to ensure unique triplets
      while(arr[i] == arr[i-1]) {
        continue;
      }

      target = -arr[i];
      twoSumSearch(arr, i+1, target, triplets);
       
    }

    cout << "------------------\n";
    return triplets;

  }


  static bool twoSumSearch(vector<int> &sorted_arr, int start_index, int target_sum, vector<vector<int>> &triplets) {

    cout << start_index << "   " << target_sum  << endl;;

    int pointer_1 = start_index;
    int pointer_2 = sorted_arr.size() - 1;

    while(pointer_1 < pointer_2) {

      if(sorted_arr[pointer_1] + sorted_arr[pointer_2] == target_sum) {

        vector<int> triplet;
        triplet.push_back(-target_sum);
        triplet.push_back(sorted_arr[pointer_1]);
        triplet.push_back(sorted_arr[pointer_2]);
        triplets.push_back(triplet);
        pointer_1++;
        pointer_2--;

        // Skip repeated numbers to ensure unique triplets
        while(pointer_1 < pointer_2 && sorted_arr[pointer_1 - 1] == sorted_arr[pointer_1]) {
          pointer_1++;
        }

        // Skip repeated numbers to ensure unique triplets
        while(pointer_1 < pointer_2 && sorted_arr[pointer_2 + 1] == sorted_arr[pointer_2]) {
          pointer_2--;
        }


      } else if(target_sum > sorted_arr[pointer_1] + sorted_arr[pointer_2]) {

        pointer_1 ++;

      } else {
        
        pointer_2 --;

      }

    }

    return false;

  }

};
  
