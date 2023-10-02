class MyLinkedList {

    class ll_node {
        public:
            int val;
            ll_node *next;

            ll_node(int valx, ll_node* nextx) {
                val = valx;
                next = nextx;
            }
    };

public:
    ll_node *head;

    MyLinkedList() {
        head = nullptr;
    }
    
    int get(int index) {

        ll_node *node = head;
        for(int i=0; i<index; i++) {
            if(node != nullptr) {
                node = node->next;
            } else {
                return -1;
            }
        }

        if(node == nullptr) return -1;

        return node->val;
    }
    
    void addAtHead(int val) {
        ll_node *new_head = new ll_node(val, head);
        head = new_head;
    }
    
    void addAtTail(int val) {

        ll_node *temp_ll = head;

        if(head == nullptr) {
            head = new ll_node(val, nullptr);
            return;
        }

        while(temp_ll->next != nullptr) {
            temp_ll = temp_ll->next;
        }

        temp_ll->next = new ll_node(val, nullptr);
        
    }
    
    void addAtIndex(int index, int val) {

        if(index == 0) {
            return addAtHead(val);
        }

        ll_node *temp_ll = head;
        ll_node *prev_ll = nullptr;
        for(int i=0; i<index; i++) {
            if(temp_ll == nullptr) {
                return;
            } else {
                prev_ll = temp_ll;
                temp_ll = temp_ll->next;
            }
        }

        prev_ll->next = new ll_node(val, temp_ll);
    }
    
    void deleteAtIndex(int index) {
        if(index == 0) {
            if(head != nullptr) {
                head = head->next;
            } else {
                return;
            }
        }

        ll_node *temp_ll = head;
        ll_node *prev_ll = nullptr;
        for(int i=0; i<index; i++) {
            if(temp_ll == nullptr) {
                return;
            } else {
                prev_ll = temp_ll;
                temp_ll = temp_ll->next;
            }
        }

        if(prev_ll != nullptr && temp_ll != nullptr) {
            prev_ll->next = temp_ll->next;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
