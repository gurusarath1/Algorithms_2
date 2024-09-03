class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        map<int,int> occ;

        for(int n : arr) {
            occ[n] = occ[n] + 1;
        }

        auto it = occ.begin();
        set<int> occ_set;

        while(it != occ.end()) {
            if(occ_set.find(it->second) != occ_set.end()) {
                return false;
            }

            occ_set.insert(it->second);

            it++;
        }

        return true;
        
    }
};
