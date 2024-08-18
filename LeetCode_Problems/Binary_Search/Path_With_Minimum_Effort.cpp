class Solution {
public:

    bool is_valid_index(vector<vector<int>> &heights, int i, int j) {

        if(i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size()) return false;

        return true;
    }


    bool is_possible(vector<vector<int>> &heights, int max_effort) {

        vector<vector<int>> dir_vecs = { {1,0} , {0,1} , {0,-1}, {-1,0} };

        int rows = heights.size(); int cols = heights[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        queue<pair<int,int>> q;
        q.push(pair<int,int>{0,0}); // Start tile

        while(!q.empty()) {

            pair<int,int> current_tile = q.front();
            q.pop();

            // Destination reached ?
            if(current_tile.first == rows - 1 
                && current_tile.second == cols - 1) {
                    return true;
            }

            // Check all directions
            for(vector<int> &dir : dir_vecs) {

                pair<int,int> next_tile;
                next_tile.first = dir[0] + current_tile.first;
                next_tile.second = dir[1] + current_tile.second;

                // Is valid next tile ?
                if(is_valid_index(heights, next_tile.first, next_tile.second)) {

                    int effort = abs(heights[current_tile.first][current_tile.second] - 
                                        heights[next_tile.first][next_tile.second]);

                    // if not visited and effort is less than max effort
                    if(visited[next_tile.first][next_tile.second] == false 
                        && effort <= max_effort) {
                            visited[next_tile.first][next_tile.second] = true;
                            q.push(next_tile);
                    }
                }

            }

        }

        return false;

    }


    int minimumEffortPath(vector<vector<int>>& heights) {

        int low = 0;
        int high = 1000000;

        int result;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            // if we can traverse with mid or lesser effort
            if(is_possible(heights, mid)) {
                result = mid;
                high = mid - 1;
            } else { // Cannot find a path with effort less or equal to mid
                low = mid + 1;
            }
        }

        return result;
    }
};
