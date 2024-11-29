class Solution {
public:

    typedef pair<vector<int>, int> pq_element_t;

    class Compare
    {
    public:
        bool operator() (pq_element_t &a, pq_element_t &b)
        {
            return a.second > b.second;
        }
    };

    int minimumTime(vector<vector<int>>& grid) {
        
        int num_rows = grid.size();
        int num_cols = grid[0].size();

        vector<int> win_state = {num_rows-1, num_cols-1};

        vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

        if(grid[0][1] > 1 && grid[1][0] > 1) {
            return -1; // stuck
        }

        vector<vector<int>> visited(num_rows, vector<int>(num_cols, false));

        priority_queue< pq_element_t , vector<pq_element_t>, Compare> pq;

        pq.push( pq_element_t{vector<int>{0,0}, grid[0][0]} ); // start state
        visited[0][0] = true;

        while(!pq.empty()) {

            pq_element_t current_node = pq.top();
            int current_time = current_node.second;
            int row = current_node.first[0];
            int col = current_node.first[1];
            pq.pop();

            if(win_state == current_node.first) {
                return current_time;
            }

            for(vector<int> &d : dir) {
                int next_row = row + d[0];
                int next_col = col + d[1];

                if(next_row >= 0 && next_col >= 0 && 
                next_row < num_rows && next_col < num_cols && 
                visited[next_row][next_col] == false) {

                    int time_to_go = grid[next_row][next_col];
                    int wait_time = 0;
                    int next_time = 0;
                    if( (time_to_go - current_time)%2 == 0 ) {
                        wait_time = 1;
                    }

                    next_time = max(time_to_go + wait_time, current_time + 1);

                    pq.push( pq_element_t{vector<int>{next_row, next_col}, next_time} );
                    visited[next_row][next_col]= true;
                }

            }

        }

        return -1;
    }
};
