class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> temp_stk;
        stack<int> idx_stk;
        vector<int> result(temperatures.size(), 0);
        
        int i = 0;
        for(int temp : temperatures) {

            while(!temp_stk.empty() && temp > temp_stk.top()) {
                result[idx_stk.top()] = i - idx_stk.top();
                temp_stk.pop();
                idx_stk.pop();
            }
            
            temp_stk.push(temp);
            idx_stk.push(i);
            
            i++;
        }
        
        return result;
    }
};
