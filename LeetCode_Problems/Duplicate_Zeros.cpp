class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        int arr_size = arr.size();
        int zero_count = 0;
        
        for(int val : arr) {
            if(val == 0) zero_count++;
        }
        
        int new_size = arr_size + zero_count;
        
        int pointer_1 = arr.size() - 1;
        arr.resize(new_size);
        int pointer_2 = arr.size() - 1;
        
        for(; pointer_1 >= 0; pointer_1--) {
            
            if(arr[pointer_1] == 0) {
                arr[pointer_2] = 0;
                pointer_2--;
                arr[pointer_2] = 0;
                pointer_2--;
            } else {
                arr[pointer_2] = arr[pointer_1];
                pointer_2--;
            }
        }
        
        arr.resize(arr_size);
        
    }
};
