class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> result;
        vector<int> nums_list;
        
        combinationSum(candidates, target, 0, nums_list, 0, result);
        
        return result;
        
    }
    
    void combinationSum(vector<int>& candidates, int target, int current_index, vector<int> &nums_list, int current_sum, vector<vector<int>> &result) {
        
        if(current_index > candidates.size() - 1) {
            return;
        }
        
        if(current_sum == target) {
            result.push_back(nums_list);
            return;
        } else if(current_sum >  target) { // No point in checking deep
            return;
        }
        
        // Don't include the number
        combinationSum(candidates, target, current_index+1, nums_list, current_sum, result);
        
        // Include the number
        current_sum = current_sum + candidates[current_index];
        nums_list.push_back(candidates[current_index]);
        // current_index is not incremented be cause we can iclude the number multiple times.
        combinationSum(candidates, target, current_index, nums_list, current_sum, result);
        nums_list.pop_back(); // Remove the current element from the list before backtracking
        
    }
};
