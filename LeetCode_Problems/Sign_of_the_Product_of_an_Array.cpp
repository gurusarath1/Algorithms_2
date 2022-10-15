class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int neg_count = 0;
        
        for(int num : nums) {
            if(num == 0) return 0;
            
            if(num < 0) neg_count++;
        }
        
        if(neg_count%2 == 0) {
            return 1;
        } else {
            return -1;
        }
    }
};
