class Solution {
public:
    bool checkIfExist(vector<int>& arr) {

        unordered_set<int> nums;

        for(int n : arr) {
            if( (n & 1) == 0 ) {
                if(nums.find(n >> 1) != nums.end()) {
                    return true;
                }
            }

            if(nums.find(n << 1) != nums.end()) {
                return true;
            }

            nums.insert(n);
        }
        
        return false;
    }
};
