class MyHashSet {
public:
    
    vector<vector<int>> table = vector<vector<int>>(100);
    
    int hash_func(int key)
    {
        return key % 100;
    }
    
    MyHashSet() {
        ;
    }
    
    void add(int key) {
        table[hash_func(key)].push_back(key);
    }
    
    void remove(int key) {
        
        int hash = hash_func(key);
        
        for(int i=0; i<table[hash].size(); i++) {
            if(table[hash_func(key)][i] == key) {
                table[hash_func(key)][i] = -1;
            }
        }
        
    }
    
    bool contains(int key) {
        int hash = hash_func(key);
        
        for(int i=0; i<table[hash].size(); i++) {
            if(table[hash_func(key)][i] == key) {
                return true;
            }
        }
        
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
