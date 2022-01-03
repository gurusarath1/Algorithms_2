class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        
        vector<int> result;
        
        int index = heights.size() - 1;
        int max_height = heights[index];
        
        result.push_back(index);
        
        index--;
        
        while(index >= 0) {
            
            if(heights[index] > max_height) {
                max_height = heights[index];
                result.push_back(index);
            }
            
            index--;
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};
