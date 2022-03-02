class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - 1;
        int mid;
        
        while(left <= right) {
            
            mid = left + (right - left) / 2;
            
            if(arr[mid] == x) {
                break;
            }
            
            if(arr[mid] > x) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        vector<int> result;
        //result.push_back(arr[mid]);
        int i = mid-1;
        int j = mid;
        
        if(i < 0) {
            i = mid;
            j = mid + 1;
        }
        
        for(int count = 0; count < k; count ++) {
            
            int left_dist = INT_MAX;
            int right_dist = INT_MAX;
            
            if(i >= 0) { left_dist = abs(arr[i] - x); }
            if(j < arr.size()) { right_dist = abs(arr[j] - x); }
        
            if(left_dist > right_dist) {
                result.push_back(arr[j]);
                j++;
            } else if (left_dist < right_dist) {
                result.push_back(arr[i]);
                i--;
            } else {
                

                    result.push_back(arr[i]);
                    i--;                    

            }
            
        }
        
        sort(result.begin(), result.end());
        
        return result;
    }
};
