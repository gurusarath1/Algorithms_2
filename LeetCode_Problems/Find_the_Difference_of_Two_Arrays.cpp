class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        set<int> num2_set;
        set<int> num1_set;

        for(int n : nums1) num1_set.insert(n);
        for(int n : nums2) num2_set.insert(n);

        vector<int> num1_not_in_num2;
        vector<int> num2_not_in_num1;

        for(int n : num1_set) {
            if(num2_set.find(n) == num2_set.end()) {
                num1_not_in_num2.push_back(n);
            }
        }

        for(int n : num2_set) {
            if(num1_set.find(n) == num1_set.end()) {
                num2_not_in_num1.push_back(n);
            }
        }

        vector<vector<int>> result;
        result.push_back(num1_not_in_num2);
        result.push_back(num2_not_in_num1);

        return result;

    }
};
