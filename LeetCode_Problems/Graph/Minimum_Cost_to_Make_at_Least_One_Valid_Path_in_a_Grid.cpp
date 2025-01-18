class Solution {
public:
    #define pii pair<int,int>
    int minCost(vector<vector<int>>& grid) {

        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        int num_rows = grid.size();
        int num_cols = grid[0].size();

        deque<pii> dq;
        dq.push_front(pii{0,0});
        vector<vector<int>> min_cost(num_rows, vector<int>(num_cols, INT_MAX));
        min_cost[0][0] = 0;

        while(dq.size()) {

            pii front = dq.front();
            auto [row, col] = front;
            dq.pop_front();

            if(row == num_rows-1 && col == num_cols-1) {
                return min_cost[row][col];
            }

            for(int i=0; i<4; i++) {

                int next_row = row + dirs[i][0];
                int next_col = col + dirs[i][1];

                if(is_valid(next_row, next_col, num_rows, num_cols)) {
                    int move_cost = (grid[row][col] != i+1);
                    int next_cost = min_cost[row][col] + move_cost;
                    if(next_cost < min_cost[next_row][next_col]) {
                        min_cost[next_row][next_col] = next_cost;

                        if(move_cost == 0) {
                            dq.push_front(pii{next_row, next_col});
                        } else {
                            dq.push_back(pii{next_row, next_col});
                        }
                    }
                }
            }

        }
        

        return INT_MAX;
    }

    bool is_valid(int row, int col, int num_rows, int num_cols) {
        if(row < 0 || col < 0 || row >= num_rows || col >= num_cols) {
            return false;
        }
        return true;
    }
};
