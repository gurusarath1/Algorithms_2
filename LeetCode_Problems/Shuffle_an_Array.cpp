class Solution {
public:
    
    vector<int> nums_original;
    vector<int> nums_shuffled;
    
    Solution(vector<int>& nums) {
        
        nums_original = nums;
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        
        return nums_original;
        
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        
        double rnd;
        unsigned long int rnd_index;
        int temp;
        
        nums_shuffled = nums_original;
        
        for(int i = 0; i < nums_shuffled.size(); i++) {
            
            rnd = i + (( (double)rand()/RAND_MAX) * (nums_shuffled.size() - i)) ;
            rnd_index = rnd;
            temp = nums_shuffled[rnd];
            nums_shuffled[rnd] = nums_shuffled[i];
            nums_shuffled[i] = temp;
            
        }
        
        return nums_shuffled;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
