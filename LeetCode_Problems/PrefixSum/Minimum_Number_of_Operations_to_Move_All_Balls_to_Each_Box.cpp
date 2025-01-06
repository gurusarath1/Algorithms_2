class Solution {
public:
    vector<int> minOperations(string boxes) {

        vector<int> suffix_array(boxes.size(), 0);
        vector<int> prefix_array(boxes.size(), 0);
        vector<int> res(boxes.size(), 0);

        int num_ones = 0;
        for(int i=suffix_array.size()-2; i>=0; i--) {
            suffix_array[i] += (boxes[i+1] - '0') + suffix_array[i+1] + num_ones;
            if(boxes[i+1]-'0' == 1) num_ones += 1;
        }

        num_ones = 0;
        for(int i=1; i<prefix_array.size(); i++) {
            prefix_array[i] += (boxes[i-1] - '0') + prefix_array[i-1] + num_ones;
            if(boxes[i-1]-'0' == 1) num_ones += 1;
        }
        
        for(int i=0; i<boxes.size(); i++) {
            res[i] = prefix_array[i] + suffix_array[i];
        }

        return res;
    }
};
