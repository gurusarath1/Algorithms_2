class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {

        map<int,int> memo;
        vector<int> ret;

        for(int n : arr1) {
            memo[n] += 1;
        }
        
        for(int n : arr2) {
            memo[n] += 1;
        }

        for(int n : arr3) {
            memo[n] += 1;
            if(memo[n] == 3) {
                ret.push_back(n);
            }
        }

        return ret;
    }
};
