/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:
    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules.

Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true


Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

*/


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        map<int, vector<char>> row_map;
        map<int, vector<char>> col_map;
        map<int, vector<char>> sub_3x3_map;
        
        int sub_3x3_box_index;
        
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[i].size(); j++) {
                
                if(board[i][j] != '.')
                {
                    // Check rows
                    if(  find(row_map[i].begin(), row_map[i].end(), board[i][j]) !=  row_map[i].end()  ) {
                        return false;
                    }

                    // Check cols
                    if(  find(col_map[j].begin(), col_map[j].end(), board[i][j]) !=  col_map[j].end()  ) {
                        return false;
                    }
                    
                    // Check 3x3 sub box
                    sub_3x3_box_index = get_3x3_sub_box_index(i,j);
                    
                    if(  find(sub_3x3_map[sub_3x3_box_index].begin(), sub_3x3_map[sub_3x3_box_index].end(), board[i][j]) !=  sub_3x3_map[sub_3x3_box_index].end()  ) {
                        return false;
                    }

                    row_map[i].push_back(board[i][j]);
                    col_map[j].push_back(board[i][j]);   
                    sub_3x3_map[sub_3x3_box_index].push_back(board[i][j]);
                }
            }
        }
        
        return true;
        
    }
    
    
    int get_3x3_sub_box_index(int row, int col) {
        
        if(row <= 2 && row >= 0 && col <= 2 && col >= 0) return 0;
        if(row <= 5 && row >= 3 && col <= 2 && col >= 0) return 1;
        if(row <= 8 && row >= 6 && col <= 2 && col >= 0) return 2;
        
        if(row <= 2 && row >= 0 && col <= 5 && col >= 3) return 3;
        if(row <= 5 && row >= 3 && col <= 5 && col >= 3) return 4;
        if(row <= 8 && row >= 6 && col <= 5 && col >= 3) return 5;
        
        if(row <= 2 && row >= 0 && col <= 8 && col >= 6) return 6;
        if(row <= 5 && row >= 3 && col <= 8 && col >= 6) return 7;
        if(row <= 8 && row >= 6 && col <= 8 && col >= 6) return 8;
        
        return -1; //invalid indices
    }
};
