#include <iostream>
#include <vector>

using namespace std;

int support_solve_MinJumpsToReachEnd(vector<int> &jump_list, int current_index, int current_num_jumps);

int solve_MinJumpsToReachEnd(vector<int> &jump_list) {

    return support_solve_MinJumpsToReachEnd(jump_list, 0, 0);

}


int support_solve_MinJumpsToReachEnd(vector<int> &jump_list, int current_index, int current_num_jumps) {

    if(current_index == jump_list.size() - 1) {
        return current_num_jumps;
    }

    if(current_index > jump_list.size() - 1) {
        return INT_MAX;
    }

    int min_jumps = jump_list.size();
    int num_jumps_required;
    for(int i=1; i<=jump_list[current_index]; i++) {

        num_jumps_required = support_solve_MinJumpsToReachEnd(jump_list, current_index+i, current_num_jumps + 1);

        if(num_jumps_required < min_jumps) {
            min_jumps = num_jumps_required;
        }
    }

    return min_jumps;

}

int main() {

    vector<int> a = {1,1,3,6,9,3,0,1,3};
    vector<int> b = {2,1,1,1,4};

    cout << solve_MinJumpsToReachEnd(a) << endl; //4
    cout << solve_MinJumpsToReachEnd(b) << endl; //3

    return 0;
}
