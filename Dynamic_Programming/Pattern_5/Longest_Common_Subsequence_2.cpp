#include <iostream>
#include <vector>

using namespace std;

int support_solve_longest_common_subsequence(string &str1, string &str2, int index_1, int index_2, vector<vector<int>> &memo);

int solve_longest_common_subsequence(string &str1, string &str2) {

    vector<vector<int>> memo(str1.size(), vector<int>(str2.size(), -1));

    return support_solve_longest_common_subsequence(str1, str2, 0, 0, memo);

}

int support_solve_longest_common_subsequence(string &str1, string &str2, int index_1, int index_2, vector<vector<int>> &memo) {

    int path_1 = 0, path_2 = 0;

    if(index_1 >= str1.size() || index_2 >= str2.size()) {
        return 0;
    }

    if(memo[index_1][index_2] != -1) {
        return memo[index_1][index_2];
    }

    if(str1[index_1] == str2[index_2]) {

        path_1 = 1 + support_solve_longest_common_subsequence(str1, str2, index_1+1, index_2+1, memo);

    } else {

        path_1 = support_solve_longest_common_subsequence(str1, str2, index_1+1, index_2, memo);
        path_2 = support_solve_longest_common_subsequence(str1, str2, index_1, index_2+1, memo);

    }

    memo[index_1][index_2] = max(path_1, path_2);

    return memo[index_1][index_2];

}


int main() {

    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    cout << solve_longest_common_subsequence(s1, s2); //4

    return 0;
}