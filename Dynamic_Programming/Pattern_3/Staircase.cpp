#include <iostream>

using namespace std;

int solve_Staircase(int num_steps) {

    if(num_steps == 0) {
        return 1;
    } else if(num_steps < 0) {
        return 0;
    }

    return solve_Staircase(num_steps - 1) + solve_Staircase(num_steps - 2) + solve_Staircase(num_steps - 3);

}

int main() {


    cout << solve_Staircase(4);

    return 0;
}
