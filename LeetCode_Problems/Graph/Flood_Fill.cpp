class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        vector<vector<int>> result = image;
        //vector<vector<int>> added_to_q(image.size(), vector<int>(image[0].size(), 0));
        set<vector<int>> added_to_q;
        int oldColor = image[sr][sc];
        
        queue<vector<int>> q;
        
        q.push({sr, sc});
        
        vector<int> next_tile(2);
        
        vector<vector<int>> vecs = { {0,1}, {1,0}, {-1,0}, {0,-1} };
        
        while(!q.empty()) {
            vector<int> current_tile = q.front();
            q.pop();
            
            result[ current_tile[0] ][ current_tile[1] ] = newColor;
            
            for(vector<int> vec : vecs) {
                
                next_tile[0] = current_tile[0] + vec[0];
                next_tile[1] = current_tile[1] + vec[1];
                
                if( next_tile[0] >= 0 && next_tile[0] < image.size() && next_tile[1] >= 0 && next_tile[1] < image[0].size() ) {
                    if(image[next_tile[0]][next_tile[1]] != newColor && image[next_tile[0]][next_tile[1]] == oldColor)
                    {
                        if(added_to_q.find(next_tile) == added_to_q.end()) {
                            q.push(next_tile);
                            added_to_q.insert(next_tile);
                        }
                    }
                }
                
                
            }
            
        }
        
        return result;
        
    }
};
