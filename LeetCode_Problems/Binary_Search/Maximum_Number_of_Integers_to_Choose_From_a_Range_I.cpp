class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {

        sort(banned.begin(), banned.end());

        int count = 0;
        for(int i=1; i<=n; i++) {

            int low=0;
            int high=banned.size()-1;
            bool found = false;
            int target = i;
            while(low <= high) {
                int mid = low + (high - low) / 2;

                if(banned[mid] == target) {
                    found = true;
                    break;
                } else if(banned[mid] > target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }

            }

            if(found) continue;

            maxSum -= i;
            if(maxSum < 0) break;

            count ++;
        }
        return count;
    }
};
