class Solution {
public:
        class Compare
    {
    public:
        bool operator() (pair<double,int> a, pair<double,int> b)
        {
            return a.second < b.second;
        }
    };
    
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int> freq;
        
        for(int num : nums) {
            freq[num] += 1;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        
        for(pair<int,int> p : freq) {
            pq.push(p);
        }
        
        vector<int> result;
        for(int i=0; i<k; i++) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        
        return result;
    }
};
