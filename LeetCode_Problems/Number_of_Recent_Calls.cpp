class RecentCounter {
public:

    vector<int> q;

    RecentCounter() {
        
    }
    
    int ping(int t) {

        q.push_back(t);
        int num_pings = 0;

        int till_time = t - 3000;

        for(int i=q.size()-1; i >= 0; i--) {
            if(q[i] >= till_time) num_pings++;
        }

        return num_pings;
        
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
