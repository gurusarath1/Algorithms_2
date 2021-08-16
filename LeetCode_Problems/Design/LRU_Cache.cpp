class LRUCache {
public:
    
    struct DLL_Node {
        int key;
        int value;
        struct DLL_Node* prev;
        struct DLL_Node* next;
    };
    
    typedef struct DLL_Node DLL_Node;
    
    map<int, DLL_Node*> nodes_map;
    
    DLL_Node dummy_head;
    DLL_Node dummy_tail;
    
    int max_capacity;
    
    LRUCache(int capacity) {
        dummy_head = {.value = -1, .prev = nullptr, .next = &dummy_tail};
        dummy_tail = {.value = -1, .prev = &dummy_head, .next = nullptr};
        
        max_capacity = capacity;
    }
    
    int get(int key) {
        
        if(nodes_map.find(key) == nodes_map.end()) {
            // Not present
            return -1;
        } else {
            // Put the node in fornt of the linked ist
            remove_node(nodes_map[key]);
            add_node(nodes_map[key]);
            return nodes_map[key]->value;
        }
        
    }
    
    void put(int key, int value) {
        if(nodes_map.find(key) == nodes_map.end()) {
            // Not Present
            
            // Remove the least recently used node (Last node in the linked list)
            if(nodes_map.size() == max_capacity) {
                nodes_map.erase(dummy_tail.prev->key);
                remove_node(dummy_tail.prev);
            }
            
            DLL_Node* new_node = new DLL_Node;
            new_node->value = value;
            new_node->key = key;
            
            nodes_map[key] = new_node;
            add_node(new_node);
            
            
        } else {
            
            // Key already present
            
            DLL_Node* node = nodes_map[key];
            remove_node(node); // remove node
            node->value = value;
            add_node(node); // Re add the node
            
        }
    }

    void add_node(DLL_Node* node) {
        
        DLL_Node *head_next = dummy_head.next;
        dummy_head.next = node;
        node->next = head_next;
        node->prev = &dummy_head;
        head_next->prev = node;
        
    }
    
    void remove_node(DLL_Node* node) {
        
        DLL_Node* node_prev = node->prev;
        DLL_Node* node_next = node->next;
        node_prev->next = node_next;
        node_next->prev = node_prev;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
