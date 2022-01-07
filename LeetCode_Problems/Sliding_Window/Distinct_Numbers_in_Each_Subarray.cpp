class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        
        map<int,int> dictX;
        set<int> unique_ints;
        vector<int> result;
        int start = 0;
        
        for(int end=0; end < nums.size(); end++) {
            
            if(end < k) {
                unique_ints.insert(nums[end]);
                dictX[nums[end]]++;
                
                if(end == k-1) {
                    result.push_back(unique_ints.size());
                }
                
            } else {
                
                if(dictX[nums[start]] == 1) {
                    unique_ints.erase(nums[start]);
                }
                dictX[nums[start]]--;
                start++;
                
                unique_ints.insert(nums[end]);
                dictX[nums[end]]++;
                
                result.push_back(unique_ints.size());
            }
            
        }
        
        return result;
        
    }
};
