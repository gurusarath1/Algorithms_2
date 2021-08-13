class Solution {
public:
    
    vector<vector<int>> result;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> temp;
        
        recurse(candidates, target, 0, temp, 0);
        return result;
    }
    
    void recurse(vector<int>& candidates, int target, int current_index, vector<int> single_result, int current_sum) {
        
        if(current_sum == target) {
            result.push_back(single_result);
            return;
        }
        
        if(current_sum > target) return;
        if(current_index >= candidates.size()) return;
        
        // Don't take number
        recurse(candidates, target, current_index+1, single_result, current_sum);

        // Take the number
        single_result.push_back(candidates[current_index]);
        current_sum = current_sum + candidates[current_index];
        
        recurse(candidates, target, current_index, single_result, current_sum);
        
    }
};
