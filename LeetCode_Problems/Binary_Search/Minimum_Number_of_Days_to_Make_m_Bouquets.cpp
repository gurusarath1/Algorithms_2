class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        int start = 1;
        int end = get_max_in_array(bloomDay);
        int min_days_required = INT_MAX;
        int num_bouquets_required = m;
        int num_flowers_per_bouquet = k;

        while(start <= end) {

            int day = (start + end) / 2;

            int num_flowers = 0;
            int num_bouquets = 0;
            for(int i=0; i<bloomDay.size(); i++) {

                if(bloomDay[i] <= day) {
                    num_flowers++;
                    if(num_flowers == num_flowers_per_bouquet) {
                        num_flowers = 0;
                        num_bouquets++;
                    }
                } else {
                    num_flowers = 0;
                }

            }

            if(num_bouquets >= num_bouquets_required) {
                if(min_days_required > day) {
                    min_days_required = day;
                }
                end = day - 1;
            } else if(num_bouquets < m) {
                start = day + 1;
            }

        }

        if(min_days_required == INT_MAX) return -1;
        return min_days_required;
    }

    int get_max_in_array(vector<int>& bloomDay) {
        int max_num = INT_MIN;
        for(int num : bloomDay) {
            if(num > max_num) max_num = num;
        }

        return  max_num;
    }

};
