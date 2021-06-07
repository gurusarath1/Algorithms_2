/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        queue<Node*> nodes_queue;
        Node* current_node;
        
        if(root == nullptr) return root;
        
        nodes_queue.push(root);
        
        while(!nodes_queue.empty()) {
            
            int current_level_size = nodes_queue.size();
            
            for(int i=0; i<current_level_size; i++) {
                
                current_node = nodes_queue.front();
                nodes_queue.pop();
                if(!nodes_queue.empty()) {
                    current_node->next = nodes_queue.front();
                }
                
                if(current_node->left) nodes_queue.push(current_node->left);
                if(current_node->right) nodes_queue.push(current_node->right);
                
            }
            
            current_node->next = nullptr;
            
        }
        
        return root;
        
    }
};
