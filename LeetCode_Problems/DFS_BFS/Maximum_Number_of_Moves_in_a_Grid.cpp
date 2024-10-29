class Solution {
public:

    vector<vector<int>> vecs = { {-1,1}, {0,1}, {1,1} };
    bool max_c_reached = false;
    int maxMoves(vector<vector<int>>& grid) {

        int num_rows = grid.size();
        int num_cols = grid[0].size();

        vector<vector<int>> memo(num_rows, vector<int>(num_cols, -1));

        int max_moves = 0;
        for(int i=0; i<num_rows; i++) {
            int moves_form_here = support_maxMoves(grid, memo, i, 0);
            max_moves = max(moves_form_here, max_moves);
        }
        
        return max_moves;
    }


    int support_maxMoves(vector<vector<int>>& grid, vector<vector<int>> &memo, int r, int c) {

        int num_rows = grid.size();
        int num_cols = grid[0].size();

        if(max_c_reached) return num_cols-1;

        if(memo[r][c] != -1) return memo[r][c];

        if(c == num_cols-1) {
            memo[r][c] = 0;
            return 0;
        }

        int max_moves_from_here = 0;
        for(vector<int> &v : vecs) {
            int next_r = r + v[0];
            int next_c = c + v[1];
            if(next_r >=0 && next_r < num_rows && next_c < num_cols) {
                if(grid[next_r][next_c] > grid[r][c]) {
                    int max_move = 1 + support_maxMoves(grid, memo, next_r, next_c);
                    max_moves_from_here = max(max_moves_from_here, max_move);
                }
            }
        }

        memo[r][c] = max_moves_from_here;

        if(max_moves_from_here == num_cols-1) max_c_reached = true;

        return max_moves_from_here;

    }


};
