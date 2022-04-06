class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        unsigned long count = 0;
        
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<=arr.size() - 3; i++) {
            
            int j = i+1;
            int k = arr.size() - 1;
            
            while(j < k) {
                
                if(arr[i] + arr[j] + arr[k] < target) {
                    j++;
                } else if(arr[i] + arr[j] + arr[k] > target) {
                    k--;
                } else {
                    
                    if(arr[j] != arr[k]) {
                        int left_count = 1;
                        int right_count = 1;

                        while(j+1 < k && arr[j] == arr[j+1]) {
                            j++;
                            left_count++;
                        }

                        while(k-1 > j && arr[k] == arr[k-1]) {
                            k--;
                            right_count++;
                        }

                        count += left_count * right_count;
                        count = count % 1000000007;
                        j++;
                        k--;
                    } else {
                        count += (k-j+1) * (k-j) / 2;
                        count = count % 1000000007;
                        break;
                    }
                    
                }
            }
        }
        
        return count;
    }
};
