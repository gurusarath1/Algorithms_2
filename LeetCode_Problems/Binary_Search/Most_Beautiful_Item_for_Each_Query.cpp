class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {

        sort(items.begin(), items.end(), [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; } );

        int best_beauty = items[0][1];
        int prev_price = items[0][0];
        vector<vector<int>> items_compact;
        items_compact.push_back(vector<int>{items[0][0], items[0][1]});
        for(int i=1; i<items.size(); i++) {
            if(best_beauty < items[i][1]) {
                best_beauty = items[i][1];
            } else {
                ;
            }

            if(prev_price == items[i][0]) {
                items_compact[items_compact.size() - 1][1] = best_beauty;
            } else {
                items_compact.push_back(vector<int>{items[i][0], best_beauty});
            }

            prev_price = items[i][0];
        }

        vector<int> result;
        for(int q : queries) {

            int low = 0;
            int high = items_compact.size() - 1;
            int exact_match = false;
            while(low <= high) {
                int mid = low + (high - low) / 2;

                if(items_compact[mid][0] == q) {
                    result.push_back(items_compact[mid][1]);
                    exact_match = true;
                    break;
                } else if(items_compact[mid][0] < q) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if(exact_match == false && low > 0) {
                result.push_back(items_compact[low-1][1]);
            } else if(exact_match == false){
                result.push_back(0);
            }
        }

        return result;
    }
};
