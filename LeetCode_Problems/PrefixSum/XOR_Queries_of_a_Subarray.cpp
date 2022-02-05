class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        vector<int> prefixXor;
        
        int xorX = 0;
        for(int num : arr) {
            xorX ^= num;
            prefixXor.push_back(xorX);
        }
        
        prefixXor.push_back(xorX);
        
        vector<int> result;
        for(vector<int> query : queries) {
            
            int left = query[0];
            int right = query[1];
            
            result.push_back(prefixXor[right] ^ prefixXor[left] ^ arr[left]);
        }
        
        return result;
    }
};
