#include <iostream>
#include <vector>

using namespace std;

int support_solve_rod_cutting(vector<int> &lengths, vector<int> &prices, int rod_length, int current_cost);

int solve_rod_cutting(vector<int> &lengths, vector<int> &prices, int rod_length) {

    vector<int> memo(rod_length+1, -1);

    return support_solve_rod_cutting(lengths, prices, rod_length, 0);

}

int support_solve_rod_cutting(vector<int> &lengths, vector<int> &prices, int rod_length, int current_cost) {

    int max_price = 0;
    int price, cut_len;

    if(rod_length == 0) {
        return current_cost;
    }

    for(int i=0; i<lengths.size(); i++) {
        
        price = 0;
        cut_len = lengths[i];
        if(rod_length - cut_len >= 0) {
            price = support_solve_rod_cutting(lengths, prices, rod_length - cut_len, current_cost + prices[i]);
        }

        if(price > max_price) {
            max_price = price;
        }

    }

    return max_price;
}

int main() {

    vector<int> lengths =  {1, 2, 3, 4, 5};
    vector<int> prices = {2, 6, 7, 10, 13};
    int L = 5;

    cout << solve_rod_cutting(lengths, prices, L); // 14

    return 0;
}
