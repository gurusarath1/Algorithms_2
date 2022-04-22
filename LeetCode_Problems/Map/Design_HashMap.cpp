class MyHashMap {
public:
    
    class LL_node {
        public:
        int key;
        int value;
        LL_node* next;
        
        LL_node(int k, int v) {
            key = k;
            value = v;
            next = nullptr;
        }
    };
    
    vector<LL_node*> list;
    
    int hash_space;
    
    MyHashMap() {
        hash_space = 2339;
        
        for(int i=0; i<hash_space; i++) {
            list.push_back(new LL_node(-1,-1));
        }
    }
    
    void put(int key, int value) {
        int hash = key % hash_space;
        
        LL_node* node = list[hash];
        LL_node* prev = nullptr;
        while(node != nullptr) {
            prev = node;
            
            if(node->key == key) {
                node->value = value;
                return;
            }
            
            node = node->next;
        }
        
        prev->next = new LL_node(key, value);
        
    }
    
    int get(int key) {
        int hash = key % hash_space;
        
        LL_node* node = list[hash];
        
        while(node != nullptr) {
            
            if(node->key == key) {
                return node->value;
            }
            
            node = node->next;
        }
        
        return -1;
    }
    
    LL_node* remove_node(LL_node* node, int key) {
        
        if(node == nullptr) {
            return nullptr;
        }
        
        if(key == node->key) {
            return remove_node(node->next, key);
        }
        
        node->next = remove_node(node->next, key);
        
        return node;
    }
    
    void remove(int key) {
        int hash = key % hash_space;
        remove_node(list[hash], key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
