class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int num_cities = isConnected.size();
        int num_provinces = 0;
        vector<bool> visited_cities(num_cities, false);
        
        for(int i=0; i<num_cities; i++) {
            if(!visited_cities[i]) {
                dfs(i, visited_cities, isConnected);
                num_provinces++;
            }
        }
        
        return num_provinces;
    }
    
    void dfs(int city, vector<bool> &visited_cities, vector<vector<int>>& isConnected) {
        
        if(visited_cities[city]) return;
        
        visited_cities[city] =  true;
        
        for(int nextCity=0; nextCity<isConnected.size(); nextCity++) {
            if(isConnected[city][nextCity]) {
                dfs(nextCity, visited_cities, isConnected);
            }
        }
        
    }
};
