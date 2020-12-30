#include <iostream>
#include <vector>

using namespace std;

int support_solve_longest_common_subsequence(string &str1, string &str2, int index_1, int index_2);

int solve_longest_common_subsequence(string &str1, string &str2) {

    return support_solve_longest_common_subsequence(str1, str2, 0, 0);

}

int support_solve_longest_common_subsequence(string &str1, string &str2, int index_1, int index_2) {

    int path_1 = 0, path_2 = 0;

    if(index_1 >= str1.size() || index_2 >= str2.size()) {
        return 0;
    }

    if(str1[index_1] == str2[index_2]) {

        path_1 = 1 + support_solve_longest_common_subsequence(str1, str2, index_1+1, index_2+1);

    } else {

        path_1 = support_solve_longest_common_subsequence(str1, str2, index_1+1, index_2);
        path_2 = support_solve_longest_common_subsequence(str1, str2, index_1, index_2+1);

    }

    return max(path_1, path_2);

}


int main() {

    string s1 = "passport";
    string s2 = "ppsspt";

    cout << solve_longest_common_subsequence(s1, s2); //5

    return 0;
}