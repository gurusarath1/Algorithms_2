class SnapshotArray {
public:

    // [index][change index].first (snap id)
    // [index][change index].second (value)
    vector<vector<pair<int,int>> > history;
    int current_snap_id;
    SnapshotArray(int length) {
        history.resize(length);

        for(int i=0; i<length; i++) {
            history[i].push_back({0,0});
        }

        current_snap_id = 0;
    }
    
    void set(int index, int val) {
        history[index].push_back({current_snap_id, val});
    }
    
    int snap() {
        return current_snap_id++;
    }
    
    int get(int index, int snap_id) {
        int low = 0;
        int high = history[index].size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(history[index][mid].first <= snap_id) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if(high > -1) return history[index][high].second;

        return 0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
