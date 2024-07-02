class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        map<int,int> mp1;
        map<int,int> mp2;

        for(int& n : nums1) {
            mp1[n] = mp1[n] + 1; 
        }
        
        for(int& n : nums2) {
            mp2[n] = mp2[n] + 1;
        }


        vector<int> result;
        for(pair<int,int> p : mp1) {
            int x = p.first;

            int min_num = 0;
            if(mp2[x]) {
                if(mp2[x] > mp1[x]) {
                    min_num = mp1[x];
                } else {
                    min_num = mp2[x];
                }

                for(int i=0; i<min_num; i++) {
                    result.push_back(x);
                }
            }

        }

        return result;
    }
};
