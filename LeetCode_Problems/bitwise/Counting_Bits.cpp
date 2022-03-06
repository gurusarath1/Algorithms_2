class Solution {
public:
    
    int num_ones(int num) {
        
        int count = 0;
        
        while(num != 0) {
            num &= (num-1); // knock out the last one
            count++;
        }
        
        return count;
        
    }
    
    vector<int> countBits(int n) {
        
        vector<int> result;
        
        for(int i=0; i<=n; i++) {
            result.push_back( num_ones(i) );
        }
        
        return result;
        
    }
};
