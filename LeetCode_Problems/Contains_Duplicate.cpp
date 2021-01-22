/*
Given an array of integers, find if the array contains any duplicates.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        map<int,int> visited;
        
        for(int num : nums) {
            
            if(visited[num]) {
                return true;
            } else {
                visited[num] = 1;
            }
            
        }
        
        return false;
        
    }
};
