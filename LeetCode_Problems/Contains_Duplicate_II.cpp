/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
*/

class Solution {
public:
    
    class IntDefaultedToMinusOne {
        public:
        int val = -1;
    };
    
    
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        map<int,IntDefaultedToMinusOne> last_visited_index;
        
        for(int i=0; i<nums.size(); i++) {
            
            if(last_visited_index[nums[i]].val != -1) {
                
                // already visited
                if( abs(last_visited_index[nums[i]].val - i) <= k ) {
                    return true;
                } else {

                    last_visited_index[nums[i]].val = i;
                }
                
            } else {
                
                last_visited_index[nums[i]].val = i;
                
            }
            
        }
        
        return false;
        
    }
};
