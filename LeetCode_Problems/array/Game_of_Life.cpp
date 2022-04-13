class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> result;
        vector<vector<int>> vecs = { {0,1},{0,-1},{1,0},{-1,0},{-1,1},{1,-1},{-1,-1},{1,1} };
        
        for(int i=0; i<board.size(); i++) {
            for(int j=0;  j<board[0].size(); j++) {
                
                int num_alive = 0;
                
                for(vector<int> vec : vecs) {
                    if( i + vec[0] <= board.size() - 1 && i + vec[0] >= 0 && j + vec[1] <= board[0].size() - 1 && j + vec[1] >= 0 ) {
                        if(board[i + vec[0]][j + vec[1]]) {
                            num_alive++;
                        }
                    }
                }
                
                if(board[i][j] == 1) {
                    
                    if(num_alive == 2 || num_alive == 3) {
                        // Stay alive
                    } else {
                        // Die
                        result.push_back({i,j,0});
                    }
                    
                } else {
                    if(num_alive == 3) {
                        // Come alive
                        result.push_back({i,j,1});
                    } else {
                        // Stay Dead
                    }                    
                }
                
            }
        }
        
        // Apply all modifications
        for(vector<int> mod : result) {
            board[mod[0]][mod[1]] = mod[2];
        }
        
    }
};
