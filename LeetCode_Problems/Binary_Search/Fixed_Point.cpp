class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int l=0;
        int h=arr.size() - 1;
        int ans = -1;

        while(l <= h) {
            int m = l + (h - l) / 2;

            if(arr[m] == m) {
                ans = m;
                h = m - 1;
            } else if(arr[m] < m) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        
        return ans;
    }
};
