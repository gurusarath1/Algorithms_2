class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int near = INT_MAX;
        int index = -1;
        int i = 0;
        for(vector<int> point : points) {
            if(point[0] == x || point[1] == y) {
                int dist = abs(x - point[0]) + abs(y - point[1]);
                
                if(dist < near) {
                    near = dist;
                    index = i;
                }
            }
            
            i++;
        }
        
        if(near == INT_MAX) return -1;
        
        return index;
    }
};
