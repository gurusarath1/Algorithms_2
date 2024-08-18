class Solution {
public:

    static bool sort_key(vector<int> &a, vector<int> &b) {

        if(a[0] == b[0]) {
            if(b[1] < a[1]) {
                return true;
            } else {
                return false;
            }
        } else if (a[0] < b[0]) {
            return true;
        }

        return false;

    } 

    int maxEnvelopes(vector<vector<int>>& envelopes) {

        sort(envelopes.begin(), envelopes.end(), sort_key);

        vector<vector<int>> dp_seq;
        
        for(int i=0; i<envelopes.size(); i++) {

            if(i == 0) {
                dp_seq.push_back(envelopes[i]);
            } else {

                if(dp_seq[dp_seq.size() - 1][1] < envelopes[i][1]) {
                    dp_seq.push_back(envelopes[i]);
                } else {
                    
                    int j = 0;
                    while(j <= i) {
                        if(dp_seq[j][1] >= envelopes[i][1]) {
                            dp_seq[j][0] = envelopes[i][0];
                            dp_seq[j][1] = envelopes[i][1];
                            break;
                        }
                        j++;
                    }
                }

            }

        }

        return dp_seq.size();
    }
};
