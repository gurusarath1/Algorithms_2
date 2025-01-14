class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> res(A.size());

        vector<int> freq(A.size()+1, 0);
        int num_common = 0;

        for(int i=0; i<A.size(); i++) {
            freq[A[i]] += 1;
            freq[B[i]] += 1;

            if(freq[A[i]] == 2) {
                num_common++;
            }
            if(freq[B[i]] == 2) {
                num_common++;
            }

            if(A[i] == B[i]) num_common--;

            res[i] = num_common;
        }

        return res;
    }
};
