class Solution {
public:
    
    static bool compare(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }
    

    class Compare2
    {
    public:
        bool operator() (int a, int b)
        {
            return a > b;
        }
    };
    
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), compare);
        
        int max_num_classes = 0;
        
        priority_queue<int, vector<int>, Compare2> pq; // Keep track of currently running classes
        for(vector<int> interval : intervals) {
            
            int current_start_time = interval[0];
            int current_end_time = interval[1];
            
            while(!pq.empty() && pq.top() <= current_start_time) {
                pq.pop();
            } 
            
            pq.push(current_end_time);
            
            if(pq.size() > max_num_classes) max_num_classes = pq.size();
        }
        
        return max_num_classes;
        
    }
};
