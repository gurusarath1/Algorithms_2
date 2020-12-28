#include <iostream>
#include <vector>

using namespace std;

/*

Denominations: {1,2,3}
Total amount: 5
Output: 5
Explanation: There are five ways to make the change for '5', here are those ways:
  1. {1,1,1,1,1} 
  2. {1,1,1,2} 
  3. {1,2,2}
  4. {1,1,3}
  5. {2,3}

*/

int support_solve_coin_change(vector<int>& denominations, int amount, int current_index);

int solve_coin_change(vector<int> &denominations, int amount) {

    return support_solve_coin_change(denominations, amount, 0);

}

int support_solve_coin_change(vector<int> &denominations, int amount, int current_index) {


    if(amount == 0) {
        return 1;
    }

    if(current_index > denominations.size() - 1) {
        return 0;
    }


    int num_ways_1 = 0, num_ways_2 = 0;

    if(amount - denominations[current_index] >= 0) {
        num_ways_1 = support_solve_coin_change(denominations, amount - denominations[current_index], current_index);
    }

    num_ways_2 = support_solve_coin_change(denominations, amount, current_index + 1);

    return num_ways_1 + num_ways_2;
    
}


int main() {

    vector<int> denominations = { 1, 5, 10 };
    int amount = 12;

    cout << solve_coin_change(denominations, amount); // 4

    return 0;
}
