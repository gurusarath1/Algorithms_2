class Solution {
public:

    vector<vector<int>> motion_vecs{ {1,2},{2,1},{2,-1},{1,-2},{-1,2},{-2,1},{-1,-2},{-2,-1} };
    vector<vector<int>> result;
    int max_move_num = 0;

    vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {

        vector<vector<int>> visit_order(m, vector<int>(n,-1));

        bool res = go_search(m, n, r, c, 0, visit_order);

        if(!res) {
            visit_order[r][c] = 0;
            return visit_order;
        }
        
        return result;
    }

    bool go_search(int m, int n, int current_r, int current_c, int move_num, vector<vector<int>> &visit_order) {

        visit_order[current_r][current_c] = move_num;
        if(move_num == ((m*n)-1) ) {
            result = visit_order; // Copy solution
            return true;
        }

        for(vector<int> &vec : motion_vecs) {

            int next_r = current_r + vec[0];
            int next_c = current_c + vec[1];

            if( (next_r >= 0 && next_r < m) && (next_c >= 0 && next_c < n) ) {
                if(visit_order[next_r][next_c] == -1) {
                    bool res = go_search(m, n, next_r, next_c, move_num+1, visit_order);

                    if(res) return true;
                }
            }
        }

        visit_order[current_r][current_c] = -1;

        return false;

    }
};
