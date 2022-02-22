class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        map<double,int> strength_row;
        
        for(int i=0; i<mat.size(); i++) {
            int num_ones = 0;
            for(int j=0; j<mat[0].size(); j++) {
                if(mat[i][j]) {
                    num_ones++;
                } else {
                    break;
                }
            }
            double strength = num_ones + (0.00001*i);
            strength_row[strength] = i;
        }
        vector<int> result;
        int i = 0;
        for(pair<double,int> p : strength_row) {
            result.push_back(p.second);
            if(i == k-1) break;
            i++;
        }
        
        return result;
        
    }
};
