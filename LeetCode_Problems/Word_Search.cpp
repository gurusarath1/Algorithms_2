class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int current_index = 0;
        bool result;
        
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    
                    //cout << "First letter hit " << i << "  " << j << endl;
                    
                    vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0) );
                    result = support_exist(board, word, current_index, i, j, visited);
                }
                
                if(result) {
                    return true;
                }
            }
        }
        
        return false;
        
    }
    
    bool support_exist(vector<vector<char>>& board, string &word, int current_index, int i, int j, vector<vector<int>> &visited) {
        
        //cout << "Recursion state " << i << "  " << j << " -- " << current_index << endl;
        
        
        visited[i][j] = 1;
        
        if(current_index == word.size() - 1 && word[current_index] == board[i][j]) {
            return true;
        }
        
        vector<vector<int>> neighbours = getNeighours(i, j, board.size() - 1, board[0].size() - 1, visited);
        
        bool result = false;
        
        for(vector<int> neighbour : neighbours) {
            
            int next_x, next_y;
            
            next_x = neighbour[0];
            next_y = neighbour[1];
            
            cout << next_x << " -- " << next_y << " | " << board[next_x][next_y] << " == " << word[current_index + 1] << endl;
            
            if(board[next_x][next_y] == word[current_index + 1]) {
                
                //cout << "letter hit " << next_x << "  " << next_y << endl;
                result = support_exist(board, word, current_index + 1, next_x, next_y, visited);
            }
            
            if(result) return true;
            
        }
        
        visited[i][j] = 0;
        
        return false;
        
    }
    
    vector<vector<int>> getNeighours(int x, int y, int max_x, int max_y, vector<vector<int>> &visited) {
        
        vector<vector<int>> neighbours;
        
        if(x - 1 >= 0) {
            if(!visited[x-1][y])
                neighbours.push_back(vector<int>{x-1, y});
        }
        
        if(y - 1 >= 0) {
            if(!visited[x][y-1])
            neighbours.push_back(vector<int>{x, y-1});
        }
        


        if(x + 1 <= max_x) {
            if(!visited[x+1][y])
                neighbours.push_back(vector<int>{x+1, y});
        }
        
        if(y + 1 <= max_y) {
            if(!visited[x][y+1])
                neighbours.push_back(vector<int>{x, y+1});
        }
        

        
        /*
        if(x + 1 <= max_x && y - 1 >= 0) {
            if(!visited[vector<int>{x+1, y-1}])
                neighbours.push_back(vector<int>{x+1, y-1});
        }
        
        if(y + 1 <= max_y && x - 1 >= 0) {
            if(!visited[vector<int>{x-1, y+1}])
                neighbours.push_back(vector<int>{x-1, y+1});
        }
        
        if(x - 1 >= 0 && y - 1 >= 0) {
            if(!visited[vector<int>{x-1, y-1}])
                neighbours.push_back(vector<int>{x-1, y-1});
        }
        
        if(x + 1 <= max_x && y + 1 <= max_y) {
            if(!visited[vector<int>{x+1, y+1}])
                neighbours.push_back(vector<int>{x+1, y+1});
        }
        */
        
        return neighbours;
        
    }
};
