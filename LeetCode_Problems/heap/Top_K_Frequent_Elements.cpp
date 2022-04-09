class Solution {
public:
    
    static bool compare(pair<int,int> a, pair<int,int> b) {
        return a.second < b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
       map<int, int> freq;
        
        for(int num : nums) {
            freq[num] += 1;
        }
        
        priority_queue< pair<int,int> , vector<pair<int,int>>, function<bool(pair<int,int>, pair<int,int>)> > pq(compare);
        
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
