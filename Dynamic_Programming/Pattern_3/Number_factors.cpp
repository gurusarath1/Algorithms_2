/*
Given a number ‘n’, implement a method to count how many possible ways there are to express ‘n’ as the sum of 1, 3, or 4.
*/

#include <iostream>

using namespace std;

int solve_Number_Factors(int current_sum, int taget_sum) {

    if(current_sum == taget_sum) {
        return 1;
    } else if(current_sum > taget_sum) {
        return 0;
    }

    return solve_Number_Factors(current_sum + 1, taget_sum) + solve_Number_Factors(current_sum + 3, taget_sum) + solve_Number_Factors(current_sum + 4, taget_sum);


}

int main() {


    cout << solve_Number_Factors(0, 5) << endl;
    cout << solve_Number_Factors(0, 4) << endl;

    return 0;
}
