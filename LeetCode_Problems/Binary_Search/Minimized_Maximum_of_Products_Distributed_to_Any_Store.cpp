class Solution {
public:


    bool can_distribute(int n, int max_q, vector<int> &quantities) {

        vector<int> shops(n, 0);
        int shop=0;
        for(int item=0; item<quantities.size(); item++) {

            int num_items = quantities[item];
            for(; shop<n; shop++) {
                if(shops[shop]==0) {
                    if(num_items >= max_q) {
                        shops[shop] = max_q;
                        num_items -= max_q;
                    } else if (num_items == 0) {
                        break;
                    } else {
                        shops[shop] = num_items;
                        num_items = 0;
                        break;
                    }
                }
            } // shop

            if(num_items != 0) return false;
        }

        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {

        int max_possible_q = 0;
        for(int q : quantities) {
            max_possible_q = max(max_possible_q, q);
        }

        //sort(quantities.begin(), quantities.end(), [](int a, int b){return a > b;});

        int low = 0;
        int high = max_possible_q;
        int min_max_quantity = INT_MAX;
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(can_distribute(n, mid, quantities)) {
                high = mid - 1;
                min_max_quantity = mid;
            } else {
                low = mid + 1;
            }
        }

        return min_max_quantity;
    }
};
