class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        if(k == 0) return vector<int>(code.size(), 0);

        vector<int> ret;
        vector<int> prefix_sum;

        int current_sum=0;
        for(int i=0; i<code.size(); i++) {
            current_sum += code[i];
            prefix_sum.push_back(current_sum);
        }

        for(int i=0; i<code.size(); i++) {
            int sum_end_index = i + k;
            int sum;

            if(k > 0) {
                if(sum_end_index >= code.size()) {
                    sum_end_index = (sum_end_index % code.size());
                    sum = prefix_sum[code.size() - 1] - prefix_sum[i] + prefix_sum[sum_end_index];
                } else {
                    sum = prefix_sum[sum_end_index] - prefix_sum[i];
                }
            }

            if(k < 0) {
                if(sum_end_index < 0) {
                    if(i-1 >= 0)
                    sum = prefix_sum[i-1] + prefix_sum[code.size() - 1] - prefix_sum[code.size() - ((-k) - i + 1) ];
                    else
                    sum = prefix_sum[code.size() - 1] - prefix_sum[code.size() - (-k) - 1];
                } else {

                    sum_end_index = sum_end_index - 1;
                    if(sum_end_index >= 0)
                    sum = prefix_sum[i-1] - prefix_sum[sum_end_index]; else sum = prefix_sum[i-1];

                }
            }

            ret.push_back(sum);
        }


        return ret;
        
    }
};
