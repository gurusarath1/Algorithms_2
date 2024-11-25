class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {

        vector<vector<int>> win_state = { {1,2,3}, {4,5,0} };
        queue< pair<vector<vector<int>>, int> > q;
        set< vector<vector<int>> > visited_set;

        // Find the empty index
        int empty_index = 0;
        for(int i=0; i<2; i++) {
            for(int j=0; j<3; j++) {
                if(board[i][j] == 0) {
                    empty_index = i*3 + j;
                    break;
                }
            }
            if(empty_index) break;
        }

        q.push( {board, empty_index} );
        visited_set.insert(board);

        vector<vector<int>> dir = { {0,1}, {1,0}, {-1,0}, {0,-1} };

        int num_moves = 0;
        while(!q.empty()) {

            int num_states = q.size();

            for(int i=0; i<num_states; i++) {
                
                if(q.front().first == win_state) return num_moves;

                for(vector<int> &d : dir) {
                    int row = q.front().second / 3;
                    int col = (q.front().second > 2)? q.front().second - 3 : q.front().second;

                    int swap_row = row + d[0];
                    int swap_col = col + d[1];

                    if(swap_row >= 0 && swap_row < 2 && swap_col >= 0 && swap_col < 3) {

                        // Swap
                        q.front().first[row][col] = q.front().first[swap_row][swap_col];
                        q.front().first[swap_row][swap_col] = 0;

                        if(visited_set.find(q.front().first) == visited_set.end()) { // we don't want to go back to a visited state
                            q.push( {q.front().first, swap_row*3 + swap_col} );
                        }
                        // Remove swap
                        q.front().first[swap_row][swap_col] = q.front().first[row][col];
                        q.front().first[row][col] = 0;
                    }
                }

                visited_set.insert(q.front().first); 
                q.pop();
            }

            num_moves++;
        }
        
        return -1;
    }
};
