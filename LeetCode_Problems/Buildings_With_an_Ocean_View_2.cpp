class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        
        stack<int> s;
        stack<int> s_index;
        vector<int> result;
        
        int index = 0;
        for(int height : heights) {
            while(!s.empty() && s.top() <= height) {
                s.pop();
                s_index.pop();
            }
            s.push(height);
            s_index.push(index);
            
            index++;
        }
        
        while(!s_index.empty()) {
            result.push_back(s_index.top());
            s_index.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};
