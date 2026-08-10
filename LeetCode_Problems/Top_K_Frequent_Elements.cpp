class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int> m1;
        multimap<int,int> m2; // multimap because freqs can repeat
        for(int n : nums) {
            m1[n] = m1[n] + 1;
        }

        for(const pair<int,int> &p : m1) {
            m2.insert(pair<int,int>{-p.second, p.first});
        }

        vector<int> ret;

        map<int,int>::iterator it = m1.begin();
        int i;
        for(it = m2.begin(), i=0; i<k && it != m2.end(); ++it, ++i) {
            ret.push_back(it->second);
        }

        return ret;
    }
};
