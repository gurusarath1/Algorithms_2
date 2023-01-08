class Solution {
public:

    static bool compare_func(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {

        sort(points.begin(), points.end(), compare_func);

        int current_end_point = points[0][1];
        int arrows = 1;

        for(int i=1; i<points.size(); i++) {
            if(points[i][0] > current_end_point) {
                arrows++;
                current_end_point = points[i][1];
            }
        }

        return arrows;
    }
};
