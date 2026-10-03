class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> vals(nums.begin(), nums.end());
        int max_len = 0;

        while(vals.size() > max_len) {
            int n = *vals.begin();
            vals.erase(n);

            int current_len = 1;
            int num = n+1;
            while(!vals.empty()) {
                if(vals.find(num) != vals.end()) {
                    current_len += 1;
                    vals.erase(num);
                } else {
                    break;
                }
                num += 1;
            }

            num = n-1;
            while(!vals.empty()) {
                if(vals.find(num) != vals.end()) {
                    current_len += 1;
                    vals.erase(num);
                } else {
                    break;
                }
                num -= 1;
            }

            if(current_len > max_len) {
                max_len = current_len;
            }
        }

        return max_len;
    }
};
