class Solution {
public:

    double get_time(vector<int> &dist, int speed) {

        double total_time = 0;

        for(int i=0; i<dist.size(); i++) {
            double time; 
            if(i == dist.size() - 1) {
                time = ((double)dist[i] / (double)speed);
            } else {
                time = ceil((double)dist[i] / (double)speed);
            }
            
            total_time += time;
        }

        return total_time;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        int low = 1;
        int high = INT_MAX;
        int min_speed = -1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            double time = get_time(dist, mid);

            if(time > hour) {

                if(low == INT_MAX) break;

                low = mid + 1;
            } else {
                min_speed = mid;
                high = mid - 1;
            }

        }

        return min_speed;

    }
};
