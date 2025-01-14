class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> res(A.size());

        unordered_set<int> vals_in_a;
        unordered_set<int> vals_in_b;
        int num_common = 0;

        for(int i=0; i<A.size(); i++) {
            vals_in_a.insert(A[i]);
            vals_in_b.insert(B[i]);

            if(vals_in_a.find(B[i]) != vals_in_a.end()) {
                num_common++;
            }
            if(vals_in_b.find(A[i]) != vals_in_b.end()) {
                num_common++;
            }

            if(A[i] == B[i]) num_common--;

            res[i] = num_common;
        }

        return res;
    }
};
