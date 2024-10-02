class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        multimap<int,int> vals_index;
        vector<int> ret(arr.size());

        for(int i=0; i<arr.size(); i++) {
            vals_index.insert( pair<int,int> { arr[i] , i } );
        }

        auto it = vals_index.begin();

        int rank = 0;
        int prev_val = INT_MIN;
        while(it != vals_index.end()) {
            if(prev_val != it->first) rank++; // to take care of duplicate values
            ret[it->second] = rank;
            prev_val = it->first;
            it++;
        }
        
        return ret;
    }
};
