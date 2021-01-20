class Solution {
public:
    int numberOfMatches(int n) {
        
        int num_matches = 0;
        
        while(n != 1)
            if(n%2 == 0) {

                num_matches += (n / 2);
                n = n / 2;
            } else {
                n = n - 1;
                num_matches += (n / 2);
                n = (n / 2) + 1;
            }
        
        return num_matches;
        
    }
};
