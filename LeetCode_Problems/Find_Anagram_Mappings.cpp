class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        
        map <int, vector<int>> index_map;
        vector<int> ret(nums2.size());
        
        for(int i=0; i<nums1.size(); i++) {
            index_map[nums1[i]].push_back(i);
        }
        
        for(int i=0; i<nums2.size(); i++) {
            ret[ index_map[nums2[i]][0] ] = i;
            index_map[nums2[i]].erase(index_map[nums2[i]].begin());
        }
        
        return ret;
        
    }
};
