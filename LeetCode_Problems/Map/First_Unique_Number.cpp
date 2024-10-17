class FirstUnique {
public:

    map<int, int> is_unique;
    map<unsigned int, int> index_unique_num_map;
    vector<int> q;

    FirstUnique(vector<int>& nums) {
        q = nums;

        for(int i=0; i<q.size(); i++) {
            int n = q[i];

            if(is_unique.find(n) == is_unique.end()) {
                is_unique[n] = i+1;
                index_unique_num_map[i] = n;
            } else {
                index_unique_num_map.erase(is_unique[n] - 1);
                is_unique[n] = 0;
            }
        }
    }
    
    int showFirstUnique() {

        if(index_unique_num_map.empty()) return -1;

        auto it = index_unique_num_map.begin();

        return it->second;
    }
    
    void add(int value) {
        q.push_back(value);

        if(is_unique.find(value) == is_unique.end()) {
            is_unique[value] = q.size();
            index_unique_num_map[q.size() - 1] = value;
        } else {
            index_unique_num_map.erase(is_unique[value] - 1);
            is_unique[value] = 0;
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
