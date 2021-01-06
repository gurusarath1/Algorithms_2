/*
There are ‘n’ houses built in a line. A thief wants to steal maximum possible money from these houses.
The only restriction the thief has is that he can’t steal from two consecutive houses, as that would alert the security system. How should the thief maximize his stealing?
*/


#include <iostream>
#include <vector>

using namespace std;

int support_solve_House_thief(vector<int> &houses_list, int start_index);


int solve_House_thief(vector<int> &houses_list) {

    return support_solve_House_thief(houses_list, 0);

}

int support_solve_House_thief(vector<int> &houses_list, int start_index) {

    if(start_index >= houses_list.size()) {
        return 0;
    }

    // loot
    int loot_1 = houses_list[start_index] + support_solve_House_thief(houses_list, start_index + 2);


    // not loot
    int loot_2 = support_solve_House_thief(houses_list, start_index + 1);

    return max(loot_1, loot_2);
}



int main() {

    vector<int> houses_list = {2, 10, 14, 8, 1};

    cout << solve_House_thief(houses_list); // 18

    return 0;
}
