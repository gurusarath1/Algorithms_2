class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> result;

        result.push_back(0);

        for(int i=1; i<=n; i++)
            result.push_back(result[i/2] + i%2);
        
        return result;
    }
};
