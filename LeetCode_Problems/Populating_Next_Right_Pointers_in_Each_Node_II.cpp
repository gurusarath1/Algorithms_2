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
        
        
        if(root == nullptr) return nullptr;
        
        queue<Node*> q;
        
        q.push(root);
        
        while(!q.empty()) {
            
            int size_of_level = q.size();
            
            for(int i=0; i<size_of_level; i++) {
                
                Node* current_node = q.front();
                q.pop();
                if(i == size_of_level - 1) {
                    current_node->next = nullptr;
                } else {
                    current_node->next = q.front();
                }
                
                if(current_node->left != nullptr) q.push(current_node->left);
                if(current_node->right != nullptr) q.push(current_node->right);
            }
            
        }
        
        return root;
        
        
    }
};
